Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.

## unordered_map or int array(since the key is limited)

The important part is to process the one-to-one relationship should be fixed in two strings.

**In this case, use int array can be much faster.**


### For 1-to-1 relationship problems: code can be more concise if map letter/words to the last index they show up
Notice that the integer stored in the maps are 1-based since if one element does not exist in the map, map[element] = 0 will be set defaultly by the code when you judge the condition.


### In this solution, one thing worth noticing!! (Map and int array)

When I do this, notice why I should use i+1, not i! although logically "i" would be right!

	class Solution {
	public:
	    bool isIsomorphic(string s, string t) {
	        int n = s.size();
	        
	        unordered_map<int,int> rec1;
	        unordered_map<int,int> rec2;
	        for(int i = 0; i < n ; i++ ){
	        	// notice when I do the comparison, when s[i] or t[i] is not in the map
	        	// it will automatically create a (key,value) pair where the value = 0
	            if( rec1[s[i]] != rec2[t[i]] )
	                return false;
	            // but since the index starts from 0, it can confuse with the default value 0 when key does not exist
	            // use i+1 to avoid that
	            rec1[s[i]] = i + 1;
	            rec2[t[i]] = i + 1;            
	        }
	        return true;
	    }
	};

### for (unordered_)Map

When you refer to a key that does not exist, **map will automatically create a (key,value) pair where the value = 0**

### for int array

Since the initial value is 0, we should avoid 0 too. Also need to use i+1.  

See the sample 6ms code.
