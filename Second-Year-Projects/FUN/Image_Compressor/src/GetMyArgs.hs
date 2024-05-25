module GetMyArgs where

import MyLib

getStuff :: [String] -> String -> [Char]
getStuff (x:xs) tofind |  x == tofind = head xs
                       | otherwise = getStuff xs tofind
getStuff [] tofind = "null"

getNFlag :: [String] -> Int
getNFlag args | getStuff args "-n" == "null" = 2
              | otherwise = readInt (getStuff args "-n")

getLFlag :: [String] -> Float
getLFlag args | getStuff args "-l" == "null" = 0.5
              | otherwise = readFloat (getStuff args "-l")

getFFlag :: [String] -> IO String
getFFlag args = readFile (getStuff args "-f")