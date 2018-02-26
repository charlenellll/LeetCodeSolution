You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example 1:

	Input: J = "aA", S = "aAAbbbb"
	Output: 3

Example 2:

	Input: J = "z", S = "ZZ"
	Output: 0

Note:

S and J will consist of letters and have length at most 50.
The characters in J are distinct.

# Solutions

## 1. Unordered_set : fastest

Unordered_set's space complexity id smaller than int array in this problem since the length of J <= 50 and int array for letters has 256 elements.

## 2. int array :-( No need to use it in this problem.

### You need to know WHEN TO USE AN INT ARRAY

When the problems has (explicit or implicit) restrict of "the input consists of lower case letters only", the size of int array we need is 26, it would be smaller.

But in this case, the input consists of letters but its length <= 50, obviously using an unordered_set saves more space!

## 3. find() method of string object :-( No need to use it in this problem.

Because find() function is not in linear time! Be careful when you use it!

The C++ standard doesn't specify implementation details, and only specifies complexity requirements in some cases. The only complexity requirements on std::string operations are that size(), max_size(), operator[], swap(), c_str() and data() are all constant time. **The complexity of anything else depends on the choices made by whoever implemented the library you're using.** !!!!!

In this problem, we only need to find one letter each time, it is linear time if we use hash table.

However, the worst case find() can consume O(M\*N) time, we'd better not to use it in this problem!