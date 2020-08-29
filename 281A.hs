import Data.Char

f :: [Char] -> [Char]
f [] = []
f (x:xs) = if (length (x:xs)) <= 1000 then (if isUpper x == True then [x]++xs else convertFst (x:xs)) else "error"

convertFst :: [Char] -> [Char]
convertFst [] = []
convertFst (x:xs) = [(toUpper x)]++xs

main = do 
    xs <- getLine
    putStrLn (f xs)