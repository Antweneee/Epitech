module ArgsManagement where

import MyLib
import MyAlgo
import System.Exit ( ExitCode(ExitFailure), exitWith, exitFailure )
import Control.Exception

readFileFunc :: String -> IO ()
readFileFunc a =  do {
                    r <- try ( readFile a ) :: IO (Either SomeException String)
                    ; case r of
                      Left ex  -> print ex >> exitWith (ExitFailure 84)
                      Right val -> return ()
                    }

checkInt :: String -> IO ()
checkInt arg | readInt arg == -1 = exitWith (ExitFailure 84)
             | otherwise = return ()

checkIntOrFloat :: String -> IO ()
checkIntOrFloat arg | readFloat arg == -1 = checkInt arg
             | otherwise = return ()

checkArgs :: [String] -> Int -> IO ()
checkArgs ("-f":x:xs) count = readFileFunc x >> checkArgs xs (count - 1)
checkArgs ("-n":x:xs) count = checkInt x >> checkArgs xs (count - 1)
checkArgs ("-l":x:xs) count = checkIntOrFloat x >> checkArgs xs (count - 1)
checkArgs [] 0 = return ()
checkArgs _ _ = exitWith (ExitFailure 84)