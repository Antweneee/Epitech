module MyAlgo where

import GetMyArgs ( getLFlag, getStuff )
import DataStorage ( Centroide(Centroide), Pixel(Pixel) )
import MyLib ( myAppend, myReverse )
import PixelCreation ( createListPixel )
import System.Random ()
import GHC.Float (int2Float)
import System.Exit
    ( ExitCode(ExitSuccess),
      exitWith,
      exitSuccess,
      ExitCode(ExitFailure),
      exitWith,
      exitFailure )


algo :: [String] -> [Centroide] -> IO ()
algo args c = do
                    x <- readFile (getStuff args "-f")
                    loopAll (createListPixel x [] []) c 10 (getLFlag args)

getTheMinPosArray :: [Int] -> Int -> Int -> Int -> Int
-- renvoye la postion du plus petit int dans la list de intyy
getTheMinPosArray (x:xs) count valu pos | x < valu =
                                      getTheMinPosArray xs (count+1) x count
                                        | x >= valu =
                                      getTheMinPosArray xs (count+1) valu pos
getTheMinPosArray [] _ _ pos = pos
getTheMinPosArray _ _ _ _ = 0

addTupleValues :: (Float, Float, Float) -> Int
addTupleValues (r, g, b) = round (sqrt (r + g + b))

-- compare un pixel et un centroide pour renvoyer une value qui est est le rgb
--ajouté de la distance entre les deux points
compareTwoPoints :: Pixel -> Centroide -> Int
compareTwoPoints (Pixel t2A (a1, a2, a3)) (Centroide a (b1, b2, b3)) =
  addTupleValues (int2Float (a1 - round b1) ^ 2,
  int2Float (a2 - round b2) ^ 2, int2Float (a3 - round b3) ^ 2)

-- prend un pixel, le compare aux centroides et renvoie le numero du centroide
--auquel il est le plus proche
calculateAll :: Pixel -> [Centroide] -> [Int] -> Int
calculateAll pixel (x:xs) dif =
  calculateAll pixel xs (compareTwoPoints pixel x:dif)
calculateAll pixel [] dif =
  getTheMinPosArray (myReverse dif) 0 (head (myReverse dif)) 0
--la fonction renvoyue la position du plus petit nombre dans le tableau d'int
--soit la position du centr dans la liste avec lql le pixel est le plus proche

addPixelToCentroide :: Pixel -> [Centroide] -> [Centroide]
  -> Int -> Int -> [Centroide]
addPixelToCentroide pixel ((Centroide pixels f_rgb):xs) new count pos |
  count == pos =
    addPixelToCentroide pixel xs
    (myAppend new [Centroide (myAppend pixels [pixel]) f_rgb]) (count + 1) pos
  | otherwise =
    addPixelToCentroide pixel xs
    (myAppend new [Centroide pixels f_rgb]) (count + 1) pos
addPixelToCentroide _ _ new _ _ = new

-- fonction de transition entre classMyCentroide et calculateAll
doAssignations :: Pixel -> [Centroide] -> [Centroide]
doAssignations pixel centroides = addPixelToCentroide pixel centroides []
  0 (calculateAll pixel centroides [])

-- prend tout les pixels du fichier et les k centroides
classMyCentroide :: [Pixel] -> [Centroide] -> [Centroide]
classMyCentroide xs centroides = foldl (flip doAssignations) centroides xs

clearCentroides :: [Centroide] -> [Centroide] -> [Centroide]
clearCentroides [] new = new
clearCentroides ((Centroide pixels f_rgb):xs) new =
  clearCentroides xs (myAppend new [Centroide [] f_rgb])

loopAll :: [Pixel] -> [Centroide] -> Int -> Float -> IO ()
loopAll _ centroides 0 _ = finalPrint centroides
loopAll pixels centroides count l =
  preCheck (changeTheMean (classMyCentroide pixels
  (clearCentroides centroides [])) []) centroides (length centroides - 1) 0 l
  >> loopAll pixels (changeTheMean (classMyCentroide pixels
  (clearCentroides centroides [])) []) (count - 1) l

changeTheMean :: [Centroide] -> [Centroide] -> [Centroide]
changeTheMean [] new = new
changeTheMean ((Centroide pixels f):xs) new =
  changeTheMean xs (myAppend new [Centroide pixels (checkTheMean pixels f)])

-- assigne des pixel a des centroides en fonction de leur value

preCheck :: [Centroide] -> [Centroide] -> Int -> Int -> Float -> IO ()
preCheck a b = checcdt a b a

checcdt :: [Centroide] -> [Centroide] -> [Centroide] -> Int
  -> Int -> Float -> IO ()
checcdt ((Centroide _ f_rgb1):fs) ((Centroide _ f_rgb2):ss) nrml len actual l |
  len == actual =
    finalPrint nrml >> exitSuccess
  | otherwise =
    checcdt fs ss nrml len (actual + checkStopCondition f_rgb1 f_rgb2 l) l
checcdt _ _ _ _ _ _ = return ()

checkStopCondition :: (Float, Float, Float) ->
  (Float, Float, Float) -> Float -> Int
checkStopCondition (a, b, c) (d, e, f) dif
  | abs ((a + b + c) - (d + e + f)) < dif = 1
  | otherwise = 0


--, fait une nouvelle moyenne de pixel

checkTheMean :: [Pixel] -> (Float, Float, Float) -> (Float, Float, Float)
checkTheMean pixels l | addTupleValues (doTheMean pixels (0, 0, 0) 0) == 0 = l
                        | otherwise = doTheMean pixels (0, 0, 0) 0

-- prend une lsite de pixel un tuple de 0 (la moyenne) et un compteur
doTheMean :: [Pixel] -> (Float, Float, Float) -> Int -> (Float, Float, Float)
doTheMean (x:xs) mean count = doTheMean xs (addPixelToTuple x mean) (count + 1)
doTheMean [] mean count = meanATuple mean count
-- ajoute au tuple les valeur du tuple rgb du pixel
-- une fois que toute les valeurs ont été ajoutées, elles sont divisées
-- par le nombre de pixel pour la moyenne

-- divise un tuple par un nombre pour en obtenir une moyenne
meanATuple :: (Float, Float , Float) -> Int -> (Float, Float, Float)
meanATuple (r, g, b) 0 = (r, g, b)
meanATuple (r, g, b) count
  = (r / int2Float count, g / int2Float count, b / int2Float count)

-- ajoute les valeurs rgb du tuple d'un pixel à un autre tuple et le retourne
addPixelToTuple :: Pixel -> (Float, Float, Float) -> (Float, Float, Float)
addPixelToTuple (Pixel p_position (rp, gp, bp)) (r, g, b) =
  (int2Float rp + r,int2Float gp + g,int2Float bp + b)


-- 1 assigne des pixel a des centroides en fonction de leur value


-- 2 fait une nouvelle moyenne de pixel


-- 3 reassigne des pixels

roundTuple :: (Float, Float, Float) -> (Int, Int, Int)
roundTuple (a, b, c) = (round a, round b, round c)

finalPrintPixels :: [Pixel] -> IO ()
finalPrintPixels ((Pixel p_position p_rgb):xs) = putStr (show p_position)
                                                >> putChar ' '
                                                >> print p_rgb
                                                >> finalPrintPixels xs
finalPrintPixels [] = return ()


finalPrint :: [Centroide] -> IO ()
finalPrint ((Centroide pixels f_rgb):xs) = putStrLn "--" >>
                            print (roundTuple f_rgb) >> putStrLn "-"
                            >> finalPrintPixels pixels
                            >> finalPrint xs
finalPrint [] = return ()