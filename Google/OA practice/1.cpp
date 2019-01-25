#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

class Solution{
public:
    int findUniqEmail(vector<string>& emails){
        unordered_map<string, int> uniqEmails;
        int cnt = 0;
        for( auto input: emails){
            int tail = input.size()-1, head = 0;
            while( tail >= 0 ){
                if( input[tail] != '@') tail--;
                else break;
            }
            string res = "";
            while( head < tail){
                if( input[head] == '+') break;
                if( input[head] != '.' || (input[head] == '.' && head == 0)) res += input[head];
                head ++;
            }
            res = res + input.substr(tail);
            uniqEmails[res] ++;
        }
        for(auto iter: uniqEmails){
            if(iter.second > 1 ) cnt ++;
        }
        return cnt;
    }
};

int main() {
    Solution s;
    string inputs[] = {"dupli......cate@example.com", "d.u.p.l.i.c.a.t.e@example.com", "a.b@example.com", };
    vector<string> emails(inputs, inputs+3);
    int res  = s.findUniqEmail(emails);
    cout << res;
    return 0;
}