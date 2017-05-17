module WordTree(WordTree(Word, Subword, Root), emptyTree, getAllPaths, addWords, deleteWords, getWordsBeginWith) where

data WordTree = Word String | Subword String [WordTree] | Root [WordTree]

emptyTree :: WordTree
emptyTree = Root []
-- DO NOT MODIFY ABOVE
getAllPaths :: WordTree -> [[String]]
getAllPaths (Root xs)       = if null xs then [] else foldl1 (++) (map getAllPaths xs) 
getAllPaths (Subword y ys)  = map (y:) (foldl1 (++) (map getAllPaths ys) )
getAllPaths (Word x)        = [[x]]
---------------------------
getWordsBeginWith :: WordTree -> String -> [String]
getWordsBeginWith (Root xs) s        = if null xs then [] else foldl1 (++) (map (flip getWordsBeginWith s) xs)
getWordsBeginWith (Subword x xs) s   = if isInc x s then map (x++) (foldl1 (++) (map (flip getWordsBeginWith (strDiff x s)) xs)) else []
getWordsBeginWith (Word x) s         = if isInc x s then [x] else []

strDiff :: String -> String -> String
strDiff x ""    = ""
strDiff "" s    = ""
strDiff x s     
    | length s > length x = [ c | i <- [(length x)..(length s)-1], let c = s !! i ]
    | otherwise           = ""

isInc :: String -> String -> Bool
isInc x ""            = True
isInc "" s            = False
isInc x s             = foldl1 (&&) [ eq | (x1,x2) <- (zip x s), let eq = (x1 == x2)]
---------------------------
instance Show WordTree where
    show (Root xs)          = if null xs then "" else foldl1 (++) (map show xs)
    show (Subword x xs)     = x ++ ":\n" ++ foldl1 (++) (map show (map addInd (map (addPre x) xs))) 
    show (Word x)           = x ++ "\n"

addPre :: String -> WordTree -> WordTree
addPre x (Subword y ys) = Subword (x++y) ys
addPre x (Word y)       = Word (x++y)

addInd :: WordTree -> WordTree
addInd (Subword y ys)   = Subword ("  " ++ y) ys
addInd (Word y)         = Word ("  " ++ y)
---------------------------
addWords :: WordTree -> [String] -> WordTree
addWords (Root xs) []           = (Root xs)
addWords (Root xs) (y:ys)       = addWords (addHelper (Root xs) y) ys

addHelper :: WordTree -> String -> WordTree
addHelper (Root xs) s
    | null xs = Root [Word s]
    | foldl1 (&&) (map null (map (getCommon s) (treeToString xs))) = Root (sortTree(Word s : xs))
    | otherwise = Root (map (flip addHelper s) xs) 
addHelper (Subword x xs) s
    | null $ getCommon x s                                                             = Subword x xs 
    | foldl1 (&&) (map ("" ==) (map (getCommon (getDiff s x)) (treeToString xs)))      = if null $ getDiff x s then Subword (getCommon x s) (sortTree(Word (getDiff s x) : (xs))) else Subword (getCommon x s) (sortTree(Word (getDiff s x) : [Subword (getDiff x s) xs]))
    | otherwise                                                                        = Subword (getCommon x s) (map (flip addHelper (getDiff s x)) xs)    
addHelper (Word x) s
    | null s                 = Word x
    | null x                 = Word x
    | x == s                 = Word x
    | null $ getCommon x s   = Word x
    | otherwise = Subword (getCommon x s) [Word first, Word second]
        where
        first = if (getDiff x s) < (getDiff s x) then getDiff x s else getDiff s x
        second = if (getDiff x s) > (getDiff s x) then getDiff x s else getDiff s x

treeToString :: [WordTree] -> [String]
treeToString [] = []
treeToString ((Subword x xs):ys) =  [x] ++ treeToString ys
treeToString ((Word x):ys)       =  [x] ++ treeToString ys

sortTree :: [WordTree] -> [WordTree]
sortTree []                 =  []
sortTree (x:xs)             =   
    let smallerSort = sortTree (filter (sortHelper x 0) xs)
        biggerSort  = sortTree (filter (sortHelper x 1) xs)
    in smallerSort ++ [x] ++ biggerSort

sortHelper :: WordTree -> Int -> WordTree -> Bool
sortHelper (Subword x xs) d (Subword y ys) = if d == 0 then x > y else y > x 
sortHelper (Word x) d (Word y)             = if d == 0 then x > y else y > x
sortHelper (Subword x xs) d (Word y)       = if d == 0 then x > y else y > x
sortHelper (Word x) d (Subword y xs)       = if d == 0 then x > y else y > x
    
getCommon :: String -> String -> String
getCommon x ""         = ""
getCommon "" s         = ""
getCommon (x:xs) (s:ss)    = if x==s then x : (getCommon xs ss) else [] 

getDiff :: String -> String -> String
getDiff "" s            = ""
getDiff x ""            = x
getDiff (x:xs) (s:ss)   = if x /= s then (x:xs) else getDiff xs ss
---------------------------
deleteWords :: WordTree -> [String] -> WordTree
deleteWords (Root xs) []           = (Root xs)
deleteWords (Root xs) (y:ys)       = deleteWords (Root (deleteHelper (xs) y)) ys

deleteHelper :: [WordTree] -> String -> [WordTree]
deleteHelper [] y   = []
deleteHelper [Word x] y
    | x == y    = []
    | otherwise = [Word x]
deleteHelper [Subword x xs] y
    | null x                = map beautify xs
    | null (getCommon x y)  = map beautify [Subword x xs]
    | otherwise             = map beautify [Subword x (foldl1 (++) (map ((flip deleteHelper (getDiff y x)).(\x -> [x])) xs))]
deleteHelper xs y           = foldl1 (++) (map ((flip deleteHelper y).(\x -> [x])) xs)

beautify :: WordTree -> WordTree
beautify (Word x)                   = Word x
beautify (Subword x [Word y])       = Word (x++y)
beautify (Subword x [Subword y ys]) = Subword (x++y) ys
beautify (Subword x xs)             = Subword (x ++ common) (treeDif xs common) where common = (foldl1 getCommon (treeToString xs))

treeDif :: [WordTree] -> String -> [WordTree]
treeDif [] common                   = []
treeDif ((Word x):ys) common        =  (Word (getDiff x common)) : (treeDif ys common)
treeDif ((Subword x xs):ys) common  = (Subword (getDiff x common) xs) : (treeDif ys common)
-------------------------
tree2 = Root [Word "Hello"]
tree3 = Root [Subword "Hel" [Word "lo",Word "p"],Word "World"]
tree4 = Root [Subword "H" [Word "ello",Word "i"]]
tree5 = Root [Subword "He" [Word "ck",Subword "l" [Word "lo",Subword "p" [Word "",Subword "e" [Word "d",Word "r"],Word "ing"]]]]
tree6 = Root [Subword "Ca" [Subword "n" [Word "",Word "teen"],Word "ptain",Subword "r" [Word "",Subword "r" [Subword "ie" [Word "d",Word "s"],Word "y"]]],Subword "He" [Word "ck",Subword "l" [Word "lo",Subword "p" [Word "",Subword "e" [Word "d",Word "r"],Word "ing"]]]]
tree7 = Root [Subword "F" [Word "alse",Subword "i" [Word "asco",Word "le"]],Subword "Re" [Word "aper",Subword "po" [Word "",Word "sitory"]],Subword "T" [Subword "a" [Subword "il" [Word "",Word "or"],Word "p"],Word "esla"]]
tree8 = Root [Subword "He" [Word "ck",Subword "l" [Word "lo",Subword "p" [Word "",Subword "e" [Word "d",Word "r"],Word "ing"]]]]
tree9 = Root [Subword "Ca" [Subword "n" [Word "",Word "teen"],Word "ptain",Subword "r" [Word "",Subword "r" [Subword "ie" [Word "d",Word "s"],Word "y"]]],Subword "H" [Subword "e" [Word "ck",Subword "l" [Word "lo",Subword "p" [Word "",Subword "e" [Word "d",Word "r"],Word "ing"]]],Word "i"]]
tree10 = Root [Subword "Ca" [Subword "n" [Word "",Word "teen"],Word "ptain",Subword "r" [Word "",Subword "r" [Subword "ie" [Word "d",Word "s"],Word "y"]]],Subword "F" [Word "alse",Subword "i" [Word "asco",Word "le"]],Subword "He" [Word "ck",Subword "l" [Word "lo",Subword "p" [Word "",Subword "e" [Word "d",Word "r"],Word "ing"]]],Subword "Re" [Word "aper",Subword "po" [Word "",Word "sitory"]],Subword "T" [Subword "a" [Subword "il" [Word "",Word "or"],Word "p"],Word "esla"]]