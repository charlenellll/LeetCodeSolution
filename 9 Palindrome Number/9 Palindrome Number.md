Determine whether an integer is a palindrome. Do this without extra space.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.

## Reverse half of the integer and compare

The intuition if from #7 "Reverse Integer".  

+ Reverse half of this integer and compare if they are the same.
+ Notice that we have to separate different cases for even and odd number.