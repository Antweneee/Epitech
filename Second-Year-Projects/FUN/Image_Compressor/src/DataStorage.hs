module DataStorage where


data Pixel = Pixel  {  p_position :: (Int, Int)
                    ,  p_rgb :: (Int, Int, Int)
                    } deriving (Show)

data Centroide = Centroide  {  pixels :: [Pixel]
                            ,  f_rgb :: (Float, Float, Float)
                            } deriving (Show)

