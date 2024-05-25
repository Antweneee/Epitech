--
-- EPITECH PROJECT, 2022
-- B-PDG-300-PAR-3-1-PDGD02-antoine.gavira-bottari
-- File description:
-- doOp
--

myElem :: Eq a => a -> [ a ] -> Bool
myElem _ [] = False
myElem y (x:xs) = if x == y then True else myElem y xs

safeDiv :: Int -> Int -> Maybe Int
safeDiv x y = if y == 0 then Nothing else Just (x `div` y)

safeNth :: [ a ] -> Int -> Maybe a
safeNth [] _ = Nothing
safeNth (x:xs) y = if y == 0 then Just x else safeNth xs (y - 1)

safeSucc :: Maybe Int -> Maybe Int
safeSucc x = if x == Nothing then Nothing else fmap (+1) x

myLookup :: Eq a => a -> [( a , b ) ] -> Maybe b
myLookup _ [] = Nothing
myLookup i (x:xs) = if fst x == i then Just (snd x) else myLookup i xs

maybeDo :: ( a -> b -> c ) -> Maybe a -> Maybe b -> Maybe c
maybeDo _ Nothing Nothing = Nothing
maybeDo _ Nothing _ = Nothing
maybeDo _ _ Nothing = Nothing
maybeDo func (Just x) (Just y) = Just (func x y)

readInt :: [Char] -> Maybe Int
readInt "" = Nothing
readInt x = case (reads x) :: [(Int, String)] of
    [(x, "")] -> Just x
    _ -> Nothing

getLineLength :: IO Int
getLineLength = do
    str <- getLine
    return (length str)

printAndGetLength :: String -> IO Int
printAndGetLength x = putStrLn x >> return (length x)

printextremities :: Int -> Int -> Int -> IO ()
printextremities 0 _ _ = return ()
printextremities x 0 z = putStr "+" >> printextremities x 1 z
printextremities x y z =
    if y == z - 1 then putStrLn "+" >> printextremities (x-1) 0 z else
    putStr "-" >> printextremities x (y + 1) z

printmid :: Int-> Int -> Int -> IO ()
printmid 0 _ _ = return ()
printmid x 0 z = putStr "|" >> printmid x 1 z
printmid x y z =
    if y == z - 1 then putStrLn "|" >> printmid (x- 1) 0 z else
    putStr " " >> printmid x (y + 1) z

printBox :: Int -> IO ()
printBox 0 = return ()
printBox 1 = putStrLn "++" >> return ()
printBox x = if x < 0 then return () else
    printextremities 1 0 (x*2) >>
    printmid (x-2) 0 (x*2) >>
    printextremities 1 0 (x*2)

concatLine :: Int -> String -> IO String
concatLine 0 str = return str
concatLine i str = do
        x <- getLine
        concatLine (i - 1) (str ++ x)

concatLines :: Int -> IO String
concatLines x = if x <= 0 then return "" else concatLine x []