module PixelCreation where

import DataStorage ( Pixel(Pixel) )
import MyLib ( myReverse, readInt )
import Data.Char ( isDigit )

printPixels :: [Pixel] -> IO ()
printPixels = foldr ((>>) . print) (return ())

createListPixel :: [Char] -> [Char] -> [Pixel] -> [Pixel]
createListPixel [] [] pixels = myReverse pixels
createListPixel [] a pixels = myReverse (createPixel (myReverse a):pixels)
createListPixel ('\n':xs) a pixels =  createListPixel xs []
      (createPixel (myReverse a):pixels)
createListPixel (x:xs) a pixels = createListPixel xs (x:a) pixels

createPixel :: String -> Pixel
createPixel a = Pixel tuple triple
                where tuple = makeTuple (head (words a)) ("","") 0
                      triple = makeTriple (words a!!1)("","","") 0

makeTuple :: [Char] -> ([Char], [Char]) -> Int -> (Int, Int)
makeTuple ('(':xs) (b,c) v = makeTuple xs (b,c) v
makeTuple (')':xs) (b,c) v = (readInt (myReverse b), readInt (myReverse c))
makeTuple (',':xs) (b,c) v = makeTuple xs (b,c) 1
makeTuple (x:xs) (b,c) 0 | isDigit x = makeTuple xs (x:b,c) 0
makeTuple (x:xs) (b,c) 1 | isDigit x = makeTuple xs (b,x:c) 1
makeTuple _ _ _ = (1, 1)

makeTriple :: [Char] -> ([Char], [Char], [Char]) -> Int -> (Int, Int, Int)
makeTriple ('(':xs) (r,g,b) v = makeTriple xs (r,g,b) v
makeTriple (')':xs) (r,g,b) v =
      (readInt (myReverse r), readInt (myReverse g), readInt (myReverse b))
makeTriple (',':xs) (r,g,b) 0 = makeTriple xs (r,g,b) 1
makeTriple (',':xs) (r,g,b) 1 = makeTriple xs (r,g,b) 2
makeTriple (x:xs) (r,g,b) 0 | isDigit x = makeTriple xs (x:r,g,b) 0
makeTriple (x:xs) (r,g,b) 1 | isDigit x = makeTriple xs (r,x:g,b) 1
makeTriple (x:xs) (r,g,b) 2 | isDigit x = makeTriple xs (r,g,x:b) 2
makeTriple _ _ _ = (0,0,0)