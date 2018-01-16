Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “coding”, word2 = “practice”, return 3.
Given word1 = "makes", word2 = "coding", return 1.

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.

## Solution 1: unordered_map + find the min distance by loops: O(M\*N)

+ use a unordered_map<string, vector<int>> to store the indexes of each word1 and word2
+ iterate through the indexes to find the minimum distance
+ it is sometimes faster than solution 2: (it will only try the combination of indexes once)

## Solution 1 optimization! ==O(M+N)==

	while(i < hash[word1].size() && j < hash[word2].size())  
	        {  
	            minDist = min(minDist, abs(hash[word1][i]-hash[word2][j]));
	            // because I get the index vector in one pass
	            // the index in record[word1] and record[word2] must be increasing
            	// we can just move the smaller index toward the bigger one to avoid repeatedly calculate this combination  
	            hash[word1][i]<hash[word2][j]?i++:j++;  
	        }

## Solution 2: unordered_map + find the minimum in one pass: O(M\*N)

disadvantage: it tries the combination of indexes multiple times.