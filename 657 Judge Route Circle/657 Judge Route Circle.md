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

# "break" in switch-case!

**Note:**Remember to use "break" when use switch-case or you'll get totally different result.  
If I don't use break, it will not only execute the line of its case, and will execute all lines after it.

For example:

    for( int i = 0; i < moves.size(); i++ ){
        switch(moves[i]){
            case 'U':
                y++;
                // If not using break after each case, will compile error
            case 'D':
                y--;
            case 'L':
                x--;
            case 'R':
                x++;
        }
    }

if the input is 'U', it will execute: y++, y--, x--, x++  
if the input is 'D', it will execute: y--, x--, x++  
if the input is 'L', it will execute: x--, x++  
the same to 'R'

So using break is extremely important!