You are given a license key represented as a string S which consists only alphanumeric character and dashes. The string is separated into N+1 groups by N dashes.

Given a number K, we would want to reformat the strings such that each group contains exactly K characters, except for the first group which could be shorter than K, but still must contain at least one character. Furthermore, there must be a dash inserted between two groups and all lowercase letters should be converted to uppercase.

Given a non-empty string S and a number K, format the string according to the rules described above.

Example 1:

	Input: S = "5F3Z-2e-9-w", K = 4

	Output: "5F3Z-2E9W"

	Explanation: The string S has been split into two parts, each part has 4 characters.
	Note that the two extra dashes are not needed and can be removed.

Example 2:

	Input: S = "2-5g-3-J", K = 2

	Output: "2-5G-3J"

	Explanation: The string S has been split into three parts, each part has 2 characters except the first part as it could be shorter as mentioned above.

**Note**:
1. The length of string S will not exceed 12,000, and K is a positive integer.
2. String S consists only of alphanumerical characters (a-z and/or A-Z and/or 0-9) and dashes(-).
3. String S is non-empty.

## Brutal force: traverse from back, once, and arrange K alphanumerics in a group at the same time

Notice that, I've made some mistakes:  

1. We need to traverse **from the tail to the head of the string**, since all groups except the first group, need to contain K alphanumerics

2. to_string(toupper(S[i])) will return a number! If S[i] == 'k', it will return "75"
We need to use char(toupper(S[i]))

3. Because I traversed from back to front, if I accumulate res by "res += current character", the resukt "res" will be a reversed string so I used "res = current character + res". This is really slow! I believe it is because there are some really long test case and each time I call this line it will create a new string using a new address and it is really time consuming!
+ Change it to **"res += current character" and reverse it** at the end, would be way faster!

4. I could not "return reverse(res.begin(), res.end())" because, obviously, reverse() is a void function! It has no return value! Don't make this kind of mistake again just wanting to save some time! The correct use should be:  

	reverse(res.begin(), res.end())
	return res

