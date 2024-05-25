--
-- EPITECH PROJECT, 2022
-- B-PDG-300-PAR-3-1-PDGD03-antoine.gavira-bottari
-- File description:
-- Tree
--

data Tree a = Empty | Node (Tree a) a (Tree a)
    deriving (Show, Eq, Ord)

addInTree :: Ord a => a -> Tree a -> Tree a
addInTree x Empty = Node Empty x Empty
addInTree x (Node l m r) = if x >= m then (Node l m (addInTree x r)) else (Node (addInTree x l) m r)