Given a string, determine if a permutation of the string could form a palindrome.

Example 1:

	Input: "code"
	Output: false

Example 2:

	Input: "aab"
	Output: true

Example 3:

	Input: "carerac"
	Output: true

## Count all characters && 字符串分为奇数个和偶数个字符讨论

+ 字符串有奇数个字符：所有字符都要成对排在两边，只能有一个字符可以有奇数个，并且放在正中间；
+ 字符串有偶数个字符：所有字符必须是偶数个

### 回味下C++的map如何迭代

+ 用iterator:


		for( unordered_map<int,int>::iterator iter = record.begin(); iter != record.end(); iter++) 
		                    res += iter->second * (iter->second - 1);
+ 用auto：

        for( auto iter: record){
            if( iter.second % 2 != 0 ) cntOdd ++;
        }