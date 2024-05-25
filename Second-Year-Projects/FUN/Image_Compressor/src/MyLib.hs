module MyLib where

readInt :: [ Char ] -> Int
readInt string =
    case reads string :: [(Int, String)] of
      [(string, "")] -> string
      _              -> -1

readFloat :: [ Char ] -> Float
readFloat string =
    case reads string :: [(Float, String)] of
      [(string, "")] -> string
      _              -> -1

myAppend :: [ a ] -> [ a ] -> [ a ]
myAppend xs y = foldr (:) y xs

myReverse :: [ a ] -> [ a ]
myReverse [] = []
myReverse (x:xs) = myAppend (myReverse xs) [x]

myReverseTuple :: (a, b) -> (b, a)
myReverseTuple (a, b) = (b, a)