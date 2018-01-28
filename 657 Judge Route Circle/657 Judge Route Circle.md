Initially, there is a Robot at position (0, 0). Given a sequence of its moves, judge if this robot makes a circle, which means it moves back to the original place.

The move sequence is represented by a string. And each move is represent by a character. The valid robot moves are R (Right), L (Left), U (Up) and D (down). The output should be true or false representing whether the robot makes a circle.

Example 1:

	Input: "UD"
	Output: true

Example 2:

	Input: "LL"
	Output: false

# Solution

## Basic idea: unordered_map()

But it is really slow. This problem has a really convenient way:

## Use x and y index

Since each direction can only be one of the four directions, we can just use two integers x and y to represent the location of x-axis and y-axis. If we can get back to the origin (0,0) then this route is a circle, otherwise not.

This idea is really delicate.

**Note:**Remember to use "break" when use switch-case or you'll get totally different result.