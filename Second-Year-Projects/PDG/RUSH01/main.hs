--
-- EPITECH PROJECT, 2022
-- B-PDG-300-PAR-3-1-PDGRUSH1-illyas.chihi
-- File description:
-- main
--

import System.Environment
import System.Exit
import Data.List
import Data.Function

swapTwoFirst :: [Int] -> [Int]
swapTwoFirst [x] = [x]
swapTwoFirst list_a = case list_a of
    x:y:xs -> (y:x:xs)
    []     -> []

myHead :: [Int] -> [Int]
myHead [] = error "Prelude.head: empty list"
myHead (x:_) = [x]

rotateHeadToEnd :: [Int] -> [Int]
rotateHeadToEnd [] = []
rotateHeadToEnd [x] = [x]
rotateHeadToEnd (x:xs) = xs ++ [x]

rotateTailToBegin :: [Int] -> [Int]
rotateTailToBegin [] = []
rotateTailToBegin [x] = [x]
rotateTailToBegin xs = last xs : init xs

dropAndAdd :: [Int] -> [Int]
dropAndAdd [] = []
dropAndAdd list = do
    myHead list

sa :: ([Int], [Int]) -> ([Int], [Int])
sa (a, b) = ((swapTwoFirst a), b)

sb :: ([Int], [Int]) -> ([Int], [Int])
sb (a, b) = (a, (swapTwoFirst b))

sc :: ([Int], [Int]) -> ([Int], [Int])
sc (a, b) = (((swapTwoFirst a)), (swapTwoFirst b))

pa :: ([Int], [Int]) -> ([Int], [Int])
pa (a, b) = do
    let z = dropAndAdd b
    ((z ++ a), (drop 1 b))

pb :: ([Int], [Int]) -> ([Int], [Int])
pb (a, b) = do
    let z = dropAndAdd a
    ((drop 1 a), (z ++ b))

ra :: ([Int], [Int]) -> ([Int], [Int])
ra (a, b) = ((rotateHeadToEnd a), b)

rb :: ([Int], [Int]) -> ([Int], [Int])
rb (a, b) = (a, (rotateHeadToEnd b))

rr :: ([Int], [Int]) -> ([Int], [Int])
rr (a, b) = ((rotateHeadToEnd a), (rotateHeadToEnd b))

rra :: ([Int], [Int]) -> ([Int], [Int])
rra (a, b) = ((rotateTailToBegin a), b)

rrb :: ([Int], [Int]) -> ([Int], [Int])
rrb (a, b) = (a, (rotateTailToBegin b))

rrr :: ([Int], [Int]) -> ([Int], [Int])
rrr (a, b) = ((rotateTailToBegin a), (rotateTailToBegin b))

checkarg :: String -> Bool
checkarg a = case reads a :: [(Int, String)] of
        [(a, "")] -> True
        _ -> False

argumentErrors :: [String] -> IO ()
argumentErrors [] = return ()
argumentErrors (x:xs) = if checkarg x == False then exitWith (ExitFailure 84)
                                                else (argumentErrors xs)

checkaction :: String -> [String] -> Bool
checkaction _ [] = False
checkaction y (x:xs) = if y == x then True else checkaction y xs

actionErrors :: [String] -> IO ()
actionErrors [] = return ()
actionErrors (x:xs) = do
    let c =["sa", "sb", "sc", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"]
    if checkaction x c == False then exitWith (ExitFailure 84)
    else actionErrors xs


parse :: String -> ([Int], [Int]) -> ([Int], [Int])
parse "sa" list = sa list
parse "sb" list = sb list
parse "sc" list = sc list
parse "pa" list = pa list
parse "pb" list = pb list
parse "ra" list = ra list
parse "rb" list = rb list
parse "rr" list = rr list
parse "rra" list = rra list
parse "rrb" list = rrb list
parse "rrr" list = rrr list

loop :: [String] -> ([Int], [Int]) -> [Int] -> IO ()
loop [] x original = display x original >> return ()
loop (x:xs) list original = do
    let modifylist = (parse x list)
    loop xs modifylist original

display ::([Int], [Int]) -> [Int] -> IO ()
display (a, b) original = do
    let sortedlist = sort original
    if sortedlist == a && length b == 0 then putStrLn "OK"
    else putStr "KO: " >> print (a,b)
    return ()

main :: IO ()
main = do
    args <- getArgs
    if null args == True then exitWith (ExitFailure 84) else argumentErrors args
    let intlist = map (read::String->Int) args
    action <- getLine
    let actionstring = words action
    actionErrors actionstring
    loop actionstring (intlist, []) intlist
    return ()