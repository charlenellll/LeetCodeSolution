#include <iostream>
#include <cassert>
#include <cmath>
#include <unordered_map>

using namespace std;

int nswap(string& str1, string& str2) {
    int ops = 0;
    unordered_map<char, int> firstString;
    for (int i = 0; i < str1.size(); i++) {
        firstString[str1[i]] = i;
    }
    while (str1 != str2) {
        for (int i = 0; i < str2.size(); i++) {
            if( str1[i] != str2[i] && firstString.find(str2[i]) != firstString.end()) {
                int index = firstString[str2[i]];
                swap(str2[i], str2[index]);
                ops++;
            }
            if( str1 == str2 ) break;
            if (str1[i] - str2[i] == 1) {
                ops += 1;
                str2[i] += 1;
            } else if( str1[i] - str2[i] == -1){
                ops += 1;
                str2[i] -= 1;
            }
        }
    }
    return ops;
}

int main() {

    string str1, str2;
    cin >> str1 >> str2;
    assert( str1.size() <= 8 && str1.size() > 0);
    assert( str2.size() <= 8 && str2.size() > 0);
    assert( str1.size() == str2.size());
    int res = nswap(str1, str2);
    cout << res;
    return 0;
}