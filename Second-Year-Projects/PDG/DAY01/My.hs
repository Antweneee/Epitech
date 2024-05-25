--
-- EPITECH PROJECT, 2022
-- B-PDG-300-PAR-3-1-PDGD01-antoine.gavira-bottari
-- File description:
-- My
--

mySucc :: Int -> Int
mySucc x = x + 1

myIsNeg :: Int -> Bool
myIsNeg x = x < 0

myAbs :: Int -> Int
myAbs x = if x < 0
    then x * (-1)
    else x

myMin :: Int -> Int -> Int
myMin x y = if x >= y
    then y
    else x

myMax :: Int -> Int -> Int
myMax x y = if x >= y
    then x
    else y

myTuple :: a -> b -> (a , b )
myTuple x y = (x, y)

myTruple :: a -> b -> c -> (a , b , c )
myTruple x y z = (x, y ,z)

myFst :: (a , b ) -> a
myFst (x, y) = x

mySnd :: (a , b ) -> b
mySnd (x, y) = y

mySwap :: (a , b ) -> (b , a )
mySwap (x, y) = (y, x)

myHead :: [ a ] -> a
myHead [] = error "myHead List Empty"
myHead (x:_) = x

myTail :: [ a ] -> [ a ]
myTail [] = error "myTail List Empty"
myTail (_:x) = x

myLength :: [ a ] -> Int
myLength [] = 0
myLength (_:xs) = 1 + myLength xs

myNth :: [ a ] -> Int -> a
myNth [] _ = error "myNth List Empty"
myNth (x:xs) y | y == 0 = x | otherwise = myNth xs (y - 1)

myTake :: Int -> [ a ] -> [ a ]
myTake 0 _ = []
myTake _ [] = []
myTake y (x:xs) = x : myTake(y - 1) xs

myDrop :: Int -> [ a ] -> [ a ]
myDrop 0 x = x
myDrop _ [] = []
myDrop y (x:xs) = myDrop(y - 1) xs

myAppend :: [ a ] -> [ a ] -> [ a ]
myAppend [] y = y
myAppend (x:xs) (y) = x : myAppend xs y

myReverse :: [ a ] -> [ a ]
myReverse [] = []
myReverse (x:xs) = myAppend (myReverse xs) [x]

myInit :: [ a ] -> [ a ]
myInit [] = error "myInit List Empty"
myInit [x] = []
myInit (x:xs) = x : myInit xs

myLast :: [ a ] -> a
myLast [] = error "myLast List Empty"
myLast [x] = x
myLast(_:xs) = myLast xs

myZip :: [ a ] -> [ b ] -> [( a , b ) ]
myZip xs [] = []
myZip [] ys = []
myZip (x:xs) (y:ys) = (x,y) : myZip xs ys

myUnzip :: [( a , b ) ] -> ([ a ] , [ b ])
myUnzip [] = ([], [])
myUnzip ((x,y):xs) = (x : myFst (myUnzip xs), y : mySnd (myUnzip xs))

myMap :: ( a -> b ) -> [ a ] -> [ b ]
myMap func [] = []
myMap func (x:xs) = func x : myMap func xs

myFilter :: ( a -> Bool ) -> [ a ] -> [ a ]
myFilter _ [] = []
myFilter func (x:xs) | func x = x : myFilter func xs | otherwise = myFilter func xs

myFoldl :: ( b -> a -> b ) -> b -> [ a ] -> b
myFoldl func i [] = i
myFoldl func i (x:xs) = myFoldl func (func i x ) xs

myFoldr :: ( a -> b -> b ) -> b -> [ a ] -> b
myFoldr func i [] = i
myFoldr func i (x:xs) = func x (myFoldr func i xs)