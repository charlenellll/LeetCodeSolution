Table point_2d holds the coordinates (x,y) of some unique points (more than two) in a plane.
Write a query to find the shortest distance between these points rounded to 2 decimals.

	| x  | y  |
	|----|----|
	| -1 | -1 |
	| 0  | 0  |
	| -1 | -2 |
The shortest distance is 1.00 from point (-1,-1) to (-1,2). So the output should be:

	| shortest |
	|----------|
	| 1.00     |
Note: The longest distance among all the points are less than 10000.

## select min() + where

At first, the upper bound 10000 gave me an illusion of using a variable and now I know its upper bound.

In the end I realize that I don't need the variable at all.

### sqrt() + power() + round()

This needs no explanation.