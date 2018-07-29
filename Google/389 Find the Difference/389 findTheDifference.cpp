// 3. use vector: 0 ms, beats 100%
// 非常迷之不能解释:？？？？
// 1) 用vector<int> record(26, 0)在类中无论public还是private都会报错，只能用vector<int> record = vector<int>(26, 0)
// 2) 而且代码运行时间是4 ms
// 但把它放进函数里就是 0ms 了！

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> record(26, 0);
        // can there be duplicate letters in string s? Yes
        for(int i = 0; i < s.length(); i++){
            record[s[i]-'a']++;
        }
        for(int i = 0; i < t.length(); i++){
            if( record[t[i]-'a'] == 0 ) return t[i];
            record[t[i]-'a'] --;
        }
    }
};


// 2. use int[26]
// take advantage of the condition that string only contains lowercase letters
// 4 ms, beats 62.94%

class Solution {
private:
    int record[26] = {0};
public:
    char findTheDifference(string s, string t) {
        // can there be duplicate letters in string s? Yes
        for(int i = 0; i < s.length(); i++){
            record[s[i]-'a']++;
        }
        for(int i = 0; i < t.length(); i++){
            if( record[t[i]-'a'] == 0 ) return t[i]; // 包含了所有情况：t中含有s所没有的字母；以及，前面s的字母在这一步已经耗光了，t多出来一个。
            record[t[i]-'a'] --;
        }
    }
};


// 1. map: slow to iterate
// 8 ms, beats 3.29%

class Solution {
private:
    unordered_map<char, int> record;
public:
    char findTheDifference(string s, string t) {
        // can there be duplicate letters in string s?
        for(int i = 0; i < s.length(); i++){
            record[s[i]]++;
        }
        for(int i = 0; i < t.length(); i++){
            if( record.find(t[i]) ==  record.end() ) return t[i];
            record[t[i]] --;
            if( record[t[i]] == 0 ) record.erase(t[i]);
        }
        auto iter =  record.begin();
        return iter->first;
    }
};