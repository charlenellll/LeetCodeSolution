// 运行时间：5ms 占用内存：492k
class Solution {
public:
    string ReverseSentence(string str) {
        if( str.size() <= 1 ) return str;
        istringstream input(str);
        string res = "", word;
        if( !(input>>word) ){// 处理输入只有空格的情况（因为oa里的特殊test case），不然代码如下那段
            int cntBlankSpace = str.size();
            for(int i = 0; i < cntBlankSpace; i++)
                res += " ";
            return res;
        }
        res = word + " " + res;
        while(input >> word) res = word + " " + res;//记得加空格
        return res.substr(0, str.size());//去掉最后一个多加的空格
    }
};

//不考虑输入只有空格时的代码
class Solution {
public:
    string ReverseSentence(string str) {
        if( str.size() <= 1 ) return str;
        istringstream input(str);
        string res = "", word;
        while(input >> word) res = word + " " + res;//记得加空格
        return res.substr(0, str.size());//去掉最后一个多加的空格
    }
};