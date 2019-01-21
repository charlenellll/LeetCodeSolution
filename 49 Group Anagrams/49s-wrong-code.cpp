// 1. 编译错误的解法: map的键值限制 - 
// C++ map的键类型可以是一个类，比如键类型可以是C++标准库中的string类，
// 但是对作为键的类有一个约束，那就是这个类必须定义小于操作符，也就是要重载小于运算操作符
//（C++标准库的string类就定义了小于操作符）。而且这个小于操作符比较函数还必须符合“严格弱排序”，
// 简单来说就是：与自身比较时返回false，当两个键对象不存在小于关系，就视为相等；k1小于k2，k2小于k3，则k1必然小于k3。

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // assume there are no duplicate strings
        // 报错，map的键值必须是定的值，不能用数组
        unordered_map<unordered_map<char, int>, vector<string>> record;
        for(int i = 0; i < strs.size(); i++ ){
            unordered_map<char, int> characters;
            for(int j = 0; j < strs[i].size(); j++) characters[strs[i][j]]++;
            record[characters].push_back(strs[i]);
        }
        vector<vector<string>> res;
        for(auto iter: record)
            res.push_back(iter.second);
        return res;
    }
};

// 2. 编译错误的解法: sort()没有返回值，返回类型为void，它是在原地完成了排序

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        if( strs.size() == 0 ) return res;
        unordered_map<string, vector<string>> record;
        for(int i = 0; i < strs.size(); i++ ){
            string curStr = strs[i];
            string characters = sort(curStr.begin(), curStr.end());
            record[characters].push_back(curStr);
        }
        for(auto iter: record)
            res.push_back(iter.second);
        return res;
    }
};