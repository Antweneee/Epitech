module RandomGen where

import GetMyArgs ()
import System.Random ( Random(randomR), StdGen )
import DataStorage ( Centroide(Centroide) )
import GHC.Float (int2Float)

getRand :: StdGen -> (Int, StdGen)
getRand = randomR (0, 255)

gennColor :: Int -> [Int] -> StdGen -> [Int]
gennColor 0 list _ = list
gennColor i fill gen =
    gennColor (i - 1) (fst(getRand gen):fill) (snd(getRand gen))

listtoTuple :: [Int] -> (Float, Float, Float)
listtoTuple (x:y:z:xs) = (int2Float x, int2Float y, int2Float z)
listtoTuple _ = (0, 0, 0)

genePoint :: Int -> StdGen -> [Centroide] -> [Centroide]
genePoint 0 _ list = list
genePoint i gen list =
    genePoint (i-1) (snd(getRand gen))
    (Centroide [] (listtoTuple (gennColor 3 [] gen)):list)