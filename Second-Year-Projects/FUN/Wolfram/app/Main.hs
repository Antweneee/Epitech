module Main where

import Lib
import System.Environment
import System.Exit

main :: IO ()
main = do
    args <- getArgs
    if args == [] then putStrLn "Usage: --rule 30/90/110, --start 0 -> +inf , --lines 0 -> +inf, --window, --move 0 -> +inf" >> exitWith (ExitFailure 84)
    else checkArguments args ["Empty", "Empty"]
    return ()
