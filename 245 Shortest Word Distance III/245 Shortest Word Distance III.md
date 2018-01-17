This is a follow up of Shortest Word Distance. The only difference is now word1 could be the same as word2.

Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

word1 and word2 may be the same and they represent two individual words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “makes”, word2 = “coding”, return 1.
Given word1 = "makes", word2 = "makes", return 3.

Note:
You may assume word1 and word2 are both in the list.

## Same as 243 244 just add a condition of word1==word2 O(M+N)

// M = number of word1+word2, N is the total number of words

+ unordered_map 
+ iterate through record[word1] and record[word2] to find the minimum distance
	+ seperate condition when word1 == word2

// 24ms

## Optimization: when word1 == word2, I can find the answer when I establish the hash table O(N)

terminate the code earlier.

// 18 ms

## fastest: just use indexes to find out minimum distance

No need for the hash table since I don't need it anymore.  
I can take advantage of the fact that when I'm moving along the input, the index is increasing so the index I record for word1 and word2 will be the latest (aka, the largest, or, the closest) previous index so the abs() of the difference I get will be the smallest distance of current closest pair of word1 and word2. Just need to compare it to other previous closest pair of word1 and word2.

see the sample 13ms code.