import Data.Char

amountUp :: [Char] -> Int
amountUp xs = length (filter isUpper xs)

amountLo :: [Char] -> Int
amountLo xs = length (filter isLower xs)

convertionF :: [Char] -> [Char]
convertionF xs = if (amountUp xs) > (amountLo xs) then (map toUpper xs)  else (map toLower xs)

main = do 
    xs <- getLine
    putStrLn (convertionF xs)