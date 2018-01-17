There are a row of n houses, each house can be painted with one of the three colors: red, blue or green. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x 3 cost matrix. For example, costs[0][0] is the cost of painting house 0 with color red; costs[1][2] is the cost of painting house 1 with color green, and so on... Find the minimum cost to paint all houses.

Note:
All costs are positive integers.

# Dynamic Programming: Pac-man problem

Best(n) = cost(n) + Best(n-1)

In this case, just separate the situations of using different colors in n-1 problems.


### One weired thing: for the first time I discovered that I can use min({a,b,c}) to get the min value of three numbers!

	min({costs[n-1][0], costs[n-1][1], costs[n-1][2]}); // In the 3ms sample code

Need to figure out why.