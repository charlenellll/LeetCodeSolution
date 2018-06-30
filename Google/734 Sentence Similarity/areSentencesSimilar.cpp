// 10 ms, 66.99%
// 自己最直观的解法：为了比较句子同一位置两个词是否相似，要能对pairs进行查表，因此要用set。然后遍历一遍句子即可。
// O(N+P) Time, O(P) Space: N - sentence size, P - pairs size
// 有一个坑：我习惯性地爱用unordered_set（key需要hash函数），但这里只能用set（key需要比较函数），因为pair没有hash函数，需要自己传进去。

class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if( words1.size() != words2.size() ) return false;
        set<pair<string, string>> word_pairs;
        for(int i = 0; i < pairs.size(); i++){
            word_pairs.insert(pairs[i]);
        }
        for(int i = 0; i < words1.size(); i++ ){
            string word1 = words1[i];
            string word2 = words2[i];
            if( word1 != word2 && word_pairs.find(make_pair(word1, word2)) == word_pairs.end() && word_pairs.find(make_pair(word2, word1)) == word_pairs.end()) return false;
        }
        return true;
    }
};

/* 一种可能稍微更快的解法，不一定，差不多 */

// 8 ms 例程
// 把set<pair<string, string>> 换成了unordered_map<string , unordered_set<string>>
// 它这里的count函数不如我的find函数严谨！
// find()：如果key存在，则find返回key对应的迭代器，如果key不存在，则find返回unordered_map::end
// count(): count函数用以统计key值在unordered_map中出现的次数。实际上，c++ unordered_map不允许有重复的key。因此，如果key存在，则count返回1，如果不存在，则count返回0.

class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if (words1.size() != words2.size()) return false;
        unordered_map<string , unordered_set<string>> dict;
        for (pair<string, string> p : pairs) {
            dict[p.first].insert(p.second);
        }
        
        for (int i = 0; i < words1.size(); i++) {
            if (words1[i] != words2[i] && !dict[words1[i]].count(words2[i]) && !dict[words2[i]].count(words1[i]))   return false;
        }
        return true;
    }
};