The Egg Drop Problem: There is a building of 100 floors. If an egg drops from the Nth floor or
above, it will break. If it's dropped from any floor below, it will not break. You're given two eggs. Find
N, while minimizing the number of drops for the worst case.


Ans:
solve for X.

	X+(X - l)+(X- 2)+ ..• +1=100
	X(X+l)/2= 100

	X ===  13. 65
rounding to 14 drops
ex: in case it's 99 floor then drop eggs from 10. 20, 30, .... 90 = 9 drops
						95 		  = 10 drops
						91,92,93,94(96,97,98,99) 	  = 14 drops


