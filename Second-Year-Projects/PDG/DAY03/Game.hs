--
-- EPITECH PROJECT, 2022
-- B-PDG-300-PAR-3-1-PDGD03-antoine.gavira-bottari
-- File description:
-- Game
--

data Item = Sword | Bow | MagicWand
    deriving (Eq)


instance Show Item where
    show Sword = "sword"
    show Bow = "bow"
    show MagicWand = "magic wand"

data Mob = Mummy | Skeleton Item | Witch (Maybe Item)
    deriving (Eq)



createMummy :: Mob
createMummy = Mummy

createArcher :: Mob
createArcher = Skeleton Bow

createKnight :: Mob
createKnight = Skeleton Sword

createWitch :: Mob
createWitch = Witch Nothing

createSorceress :: Mob
createSorceress = Witch (Just MagicWand)

create :: String -> Maybe Mob
create "mummy" = Just createMummy
create "doomed archer" = Just createArcher
create "dead knight" = Just createKnight
create "witch" = Just createWitch
create "sorceress" = Just createSorceress
create _ = Nothing

equip :: Item -> Mob -> Maybe Mob
equip a Mummy = Nothing
equip a (Skeleton _) = Just (Skeleton a)
equip a (Witch _) = Just (Witch (Just a))

instance Show Mob where
    show Mummy = "mummy"
    show (Skeleton Bow) = "doomed archer"
    show (Skeleton Sword) = "dead knight"
    show (Skeleton x) = "skeleton holding a " ++ show x
    show (Witch Nothing) = "witch"
    show (Witch (Just MagicWand)) = "sorceress"
    show (Witch (Just x)) = "witch holding a " ++ show x

class HasItem a where
    getItem :: a -> Maybe Item
    hasItem :: a -> Bool
    hasItem a = if (getItem a) == Nothing then False else True

instance HasItem Mob where
    getItem Mummy = Nothing
    getItem (Skeleton x) = Just x
    getItem (Witch (Just x)) = Just x
    getItem (Witch (Nothing)) = Nothing