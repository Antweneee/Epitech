module Main where

import ArgsManagement
import MyAlgo
import GetMyArgs
import System.Environment ( getArgs )
import DataStorage
import System.Random
import RandomGen

main :: IO ()
main = do
        args <- getArgs
        seed <- randomIO
        checkArgs args 3
        algo args (genePoint (getNFlag args) (mkStdGen seed) [])