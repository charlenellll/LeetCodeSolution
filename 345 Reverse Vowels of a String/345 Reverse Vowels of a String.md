Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".

Note:
The vowels does not include the letter "y".

## Solution - normal swap()

(There is a special swap(): str1.swap(str2) is used to swap the content of two strings.)

The one I need is swap(s[p], s[q]), it is the normal swap we use, in an array!

### tolower()

will make it easier in the helper function so I don't need to state a e i o u A E I O U.

I can just state the lower case ones.

## special solution: find_first_of() and find_last_of()

They're built-in functions in string object. How to use them:
+ find_first_of("all the characters you want to match", start position in the string)
+ find_last_of("all the characters you want to match", end position in the string)
	+ in official document, end position means the position of the last character in the string to be considered in the search.
	+ Any value greater than, or equal to, the string length (including string::npos) means that the entire string is searched.

It saves our efforts of writing a helper function.

	p = s.find_first_of("aeiouAEIOU", p);
	q = s.find_last_of("aeiouAEIOU", q);