module Hw1 (next) where -- DO NOT CHANGE THIS

next :: [[String]] -> [[String]]
-- IMPLEMENT NEXT FUNCTION HERE --
next [["B"]] = [["W"]]
next [["W"]] = [["W"]]
next grid = [[nbct | x <- [0..w-1], let nbct = findNext x y grid]| y <- [0..h-1]]
    where
    w = length (head grid)
    h = length grid
    findNext x y grid
        | grid !! y !! x == "W" = if (countBct x y grid) == 3 then "B" else "W"
        | otherwise             = if (countBct x y grid) < 2 || (countBct x y grid) > 3 then "W" else "B"
        where
        countBct x y grid = length [ bct | i <- [-1..1], j <- [-1..1], i /= 0 || j /= 0, x+i >= 0 && x+i < w && y+j >= 0 && y+j < h, grid !! (y+j) !! (x+i) == "B", let bct = "B"]
            where
            w = length(head grid)
            h = length grid

-- DO NOT CHANGE CODE BELOW THIS LINE! --
createFile fileName = writeFile fileName ""

writeSteps filename grid n = do
                    createFile filename
                    writeStepsHelper filename grid n n
    where writeStepsHelper filename grid n all = if n == 0 then putStrLn ((show all) ++ " steps are succesfully written to \'" ++ filename ++ "\'") else do
                                    appendFile filename ((show (next grid)) ++ "\n")
                                    writeStepsHelper filename (next grid) (n-1) all