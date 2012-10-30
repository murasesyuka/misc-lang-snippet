
data RpnElem = Number Double
             | Add
             | Subtract
             | Multiple
             | Divide


rpnCalc :: [RpnElem] -> Double
rpnCalc = head . foldl rpnCalc' []


rpnCalc' :: [Double] -> RpnElem -> [Double]
            
rpnCalc' (x:y:xs) Add      = (y+x:xs)
rpnCalc' (x:y:xs) Multiple = (y*x:xs)
rpnCalc' (x:y:xs) Subtract = (y-x:xs)
rpnCalc' (x:y:xs) Divide   = (y/x:xs)
rpnCalc' xs      (Number x)= x:xs
