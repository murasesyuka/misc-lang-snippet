data Day = Sunday
         | Monday
         | Tuesday
         | Wednesday
         | Thurseday
         | Friday
         | Saturday deriving Show

isWeekend Saturday = True
isWeekend Sunday   = True
isWeekend _        = False


data Person = Person String Int deriving Show

name (Person s _) = s
age  (Person _ i) = i

kakkun61 = Person "Okamoto" 23

getOld (Person s i) = Person s (i+1)
-- succ  (Person s i) = Person s (i+1)
