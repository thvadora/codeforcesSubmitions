module Main where

import System.IO

coins :: Eq a => [a] -> Int
coins ns = length (coins' ns)

coins' :: Eq a => [a] -> [[a]]
coins' ns = foldl (flip coins'') [] ns

coins'' :: Eq a => a -> [[a]] -> [[a]]
coins'' a [] = [[a]]
coins'' a (xs:yss) | a `elem` xs = xs : (coins'' a yss)
                   | otherwise   = (a:xs):yss



main :: IO ()
main =
    do
       _ <- readInt
       str <- getLine
       ns <- return (map read $ words str :: [Int])
       putStrLn (show $ coins ns)

  where readInt :: IO Int
        readInt = readLn