// 运行时间：3ms 占用内存：476k
class Solution {
public:
    string LeftRotateString(string str, int n) {// 将前n%len位截下来放到尾部
        if( str.size() == 0 ) return str;
        n = n % str.size();
        string head = str.substr(0, n);
        string remain = str.substr(n);
        return remain + head;
    }
};