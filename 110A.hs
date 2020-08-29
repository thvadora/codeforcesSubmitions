digits :: Integer -> [Integer]
digits x = [read [n] | n <- show x]
 
countt :: [Integer] -> Integer
countt [] = 0
countt (x:xs) = if ( x == 7 || x == 4 ) then 1 + countt xs else countt xs

seteo :: Integer -> String
seteo x = if ( (countt (digits x) == 4) || (countt (digits x) == 7) ) then "YES" else "NO"

main = do
    x <- getLine
    let c = read x
    putStrLn (seteo c)