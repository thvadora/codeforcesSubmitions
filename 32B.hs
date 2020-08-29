borze1 :: String -> Bool -> String

borze1 [] _ = ""

borze1 ('.' : xs) False = '0' : borze1 xs False
borze1 ('.' : xs) True = '1' : borze1 xs False
borze1 ('-' : xs) False = borze1 xs True
borze1 ('-' : xs) True = '2' : borze1 xs False

borze :: String -> String
borze s = borze1 s False

main = do
    s <- getLine
    putStrLn (borze s)