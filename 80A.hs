import Data.List

divisibles::Integer ->[Integer]
divisibles x = [y | y <-[1..x], x `mod` y == 0]

esPrimo::Integer -> Bool
esPrimo n = length (divisibles n) <=2

listaprimos50 = filter (esPrimo) [1..52]

esnext :: Integer -> Integer
esnext n = nomaybe (find (>n) listaprimos50) 

nomaybe :: Maybe Integer -> Integer
nomaybe (Just n) = n
nomaybe _ = 0

posta :: Integer -> Integer -> [Char]
posta n s = if s == (esnext n) then ['Y','E','S'] else "NO"

yes = "YES"
no = "NO"

nomay :: Maybe Int -> Int
nomay (Just x) = x
nomay _ = 0

espacio :: [Char] -> Int
espacio xs = nomay (findIndex (== ' ') xs)

separe :: [Char] -> ([Char],[Char])
separe xs = splitAt (espacio xs) xs  

primer :: [Char] -> [Char]
primer x = fst (separe x) 

segun :: [Char] -> [Char]
segun x = snd (separe x)   



main = do 
    x <- getLine
    let t = primer x
    let h = segun x
    let n = read t
    let s = read h  
    if (posta n s) == "YES" then putStrLn (yes) else putStrLn (no)