countt :: Int -> [Char] -> Int
countt n [] = 0
countt n [x] = 0
countt n (x:y:xs) = if x == y then 1 + countt n (y:xs) else countt n (y:xs)


main = do
 n <- getLine
 ys <- getLine
 let c = read n  
 print (countt c ys)