{-# OPTIONS_GHC -Wno-incomplete-patterns #-}
{-# OPTIONS_GHC -Wno-overlapping-patterns #-}
module Lib
    ( checkArguments
    ) where
import qualified Control.Monad
import Data.Maybe
import System.Exit
import Control.Monad

removeMaybe :: Maybe Int -> Int
removeMaybe Nothing = 0
removeMaybe (Just i) = i

reverseString :: [a] -> [a]
reverseString = foldl (\acc x -> x : acc) []

printTab :: [String] -> IO ()
printTab x = Control.Monad.void (print x)

debug :: String -> IO()
debug = print

readInt :: [Char] -> Maybe Int
readInt "" = Nothing
readInt x = case reads x :: [(Int, String)] of
    [(x, "")] -> Just x
    _ -> Nothing

myAppend :: [ a ] -> [ a ] -> [ a ]
myAppend xs y = foldr (:) y xs

getWindow :: [String] -> Int
getWindow ("window":y:xs) = removeMaybe (readInt y)
getWindow [] = 80
getWindow (x:y:xs) = getWindow xs

_getLine :: [String] -> Int
_getLine [] = -1
_getLine ("lines":y:xs) = removeMaybe (readInt y)
_getLine (x:y:xs) = _getLine xs

getStart :: [String] -> Int
getStart ("lines":y:xs) = removeMaybe (readInt y)
getStart [] = 0
getStart (x:y:xs) = getStart xs

getMove :: [String] -> Int
getMove ("move":y:xs) = removeMaybe (readInt y)
getMove (x:y:xs) = getMove xs
getMove (x:y:xs) = getMove xs

createFirstLine :: Int -> Int-> [Char] -> [Char]
createFirstLine nb ini str
    | nb == ini = reverseString str
    | nb > (ini `div` 2) = createFirstLine (nb+1) ini (myAppend " " str)
    | nb == (ini `div` 2) = createFirstLine (nb+1) ini (myAppend "*" str)
    | otherwise = createFirstLine (nb+1) ini (myAppend " " str)

rule30_case :: Char -> Char -> Char -> Char
rule30_case '*' '*' '*' = ' '
rule30_case '*' '*' ' ' = ' '
rule30_case '*' ' ' '*' = ' '
rule30_case '*' ' ' ' ' = '*'
rule30_case ' ' '*' '*' = '*'
rule30_case ' ' '*' ' ' = '*'
rule30_case ' ' ' ' '*' = '*'
rule30_case ' ' ' ' ' ' = ' '

rule90_case :: Char -> Char -> Char -> Char
rule90_case '*' '*' '*' = ' '
rule90_case '*' '*' ' ' = '*'
rule90_case '*' ' ' '*' = ' '
rule90_case '*' ' ' ' ' = '*'
rule90_case ' ' '*' '*' = '*'
rule90_case ' ' '*' ' ' = ' '
rule90_case ' ' ' ' '*' = '*'
rule90_case ' ' ' ' ' ' = ' '

rule110_case :: Char -> Char -> Char -> Char
rule110_case '*' '*' '*' = ' '
rule110_case '*' '*' ' ' = '*'
rule110_case '*' ' ' '*' = '*'
rule110_case '*' ' ' ' ' = ' '
rule110_case ' ' '*' '*' = '*'
rule110_case ' ' '*' ' ' = '*'
rule110_case ' ' ' ' '*' = '*'
rule110_case ' ' ' ' ' ' = ' '

_getChar :: [Char] -> Int -> Int -> Int -> Char
_getChar [] _ _ _ = ' '
_getChar (x:xs) i pos lengh
    | pos < 0 = ' '
    | pos > lengh = ' '
    | i == pos = x
    | otherwise = _getChar xs (i+1) pos lengh

rule30 :: Int -> Int -> [Char] -> [Char] -> [Char]
rule30 i ini prev actual
    | i == ini = actual
    | otherwise = rule30 (i+1) ini prev (myAppend actual [rule30_case (_getChar prev 0 (i-1) ini) (_getChar prev 0 i ini) (_getChar prev 0 (i+1) ini)])

rule90 :: Int -> Int -> [Char] -> [Char] -> [Char]
rule90 i ini prev actual
    | i == ini = actual
    | otherwise = rule90 (i+1) ini prev (myAppend actual [rule90_case (_getChar prev 0 (i-1) ini) (_getChar prev 0 i ini) (_getChar prev 0 (i+1) ini)])

rule110 :: Int -> Int -> [Char] -> [Char] -> [Char]
rule110 i ini prev actual
    | i == ini = actual
    | otherwise = rule110 (i+1) ini prev (myAppend actual [rule110_case (_getChar prev 0 (i-1) ini) (_getChar prev 0 i ini) (_getChar prev 0 (i+1) ini)])

getRule :: [String] -> String
getRule [] = ""
getRule ("rule":y:xs) = y
getRule (x:y:xs) = getRule xs

engine :: Int -> [String] -> String -> [Char] -> [Char] -> IO ()
engine i inst rule prev actual
    | i == _getLine inst = putStrLn prev
    | rule == "30" = putStrLn prev >> engine (i+1) inst rule (rule30 0 (getWindow inst) prev actual) actual
    | rule == "90" = putStrLn prev >> engine (i+1) inst rule (rule90 0 (getWindow inst) prev actual) actual
    | rule == "110" = putStrLn prev >> engine (i+1) inst rule (rule110 0 (getWindow inst) prev actual) actual
    | otherwise = exitWith (ExitFailure 84)

errorHandler :: String -> String -> [String] -> [String] -> IO ()
erroHandler _ y xs original = exitWith (ExitFailure 84)
erroHandler x _ xs original = exitWith (ExitFailure 84)
errorHandler "Empty" "Empty" xs original = initMap xs original
errorHandler "start" str2 xs original = if isNothing (readInt str2) then exitWith (ExitFailure 84) else initMap xs original
errorHandler "lines" str2 xs original = if isNothing (readInt str2) then exitWith (ExitFailure 84) else initMap xs original
errorHandler "window" str2 xs original = if isNothing (readInt str2) then exitWith (ExitFailure 84) else initMap xs original
errorHandler "move" str2 xs original = if isNothing (readInt str2) then exitWith (ExitFailure 84) else initMap xs original
errorHandler "rule" str2 xs original = initMap xs original
errorHandler str str2 xs original= exitWith (ExitFailure 84)

initMap :: [String] -> [String] -> IO()
initMap [] origin = engine 1 origin (getRule origin) (createFirstLine 0 (getWindow origin) "") ""
initMap [x] _ = exitWith (ExitFailure 84)
initMap (x:y:xs) origin = errorHandler x y xs origin

checkInstruction :: String -> String
checkInstruction str
    | str == "--rule" = str
    | str == "--start" = str
    | str == "--lines" = str
    | str == "--window" = str
    | str == "--move" = str
    | isNothing (readInt str) = []
    | otherwise = " "

checkArguments :: [String] -> [String] -> IO ()
checkArguments [] info = initMap info info
checkArguments _ [] = exitWith (ExitFailure 84)
checkArguments ("--rule":xs) info = checkArguments xs (rule xs info)
checkArguments ("--start":xs) info = checkArguments xs (start xs info)
checkArguments ("--lines":xs) info = checkArguments xs (_lines xs info)
checkArguments ("--window":xs) info = checkArguments xs (window xs info)
checkArguments ("--move":xs) info = checkArguments xs (move xs info)
checkArguments (x:xs) info = if null (checkInstruction x) then exitWith (ExitFailure 84) else checkArguments xs info

addToTab :: [String] -> String -> [String]
addToTab xs str = foldr (:) [str] xs

start :: [String] -> [String] -> [String]
start [] _ = []
start _ [] = []
start (x:xs) info = addToTab (addToTab info "start") x

_lines :: [String] -> [String] -> [String]
_lines [] _ = []
_lines _ [] = []
_lines (x:xs) info = addToTab (addToTab info "lines") x

window :: [String] -> [String]-> [String]
window [] _ = []
window _ [] = []
window (x:xs) info = addToTab (addToTab info "window") x

move :: [String] -> [String] -> [String]
move [] _ = []
move _ [] = []
move (x:xs) info = addToTab (addToTab info "move") x


rule :: [String] -> [String] -> [String]
rule [] _ = []
rule _ [] = []
rule (x:xs) info = addToTab (addToTab info "rule") x

-- | rule == "90" = rule90 prev actual >> engine (i+1) inst rule prev actual
    -- | rule == "110" = rule110 prev actual >> engine (i+1) inst rule prev actual