// 20 ms, beats 98.82%

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> uniqEmails;
        for( auto input: emails){
            int tail = input.size()-1;
            while( tail >= 0 ){
                if( input[tail] != '@') tail--;
                else break;
            }
            string domain = input.substr(tail);
            int head = 0;
            string local = "";
            while( head < tail){
                if( input[head] == '+') break;
                if( head + 1 <= tail && head > 0 ){
                    if( input[head] == '.' && input[head-1] != '.' && input[head+1] != '.') {
                        head ++;
                        continue;
                    }
                }
                local += input[head];
                head ++;
            }
            string res = local + domain;
            if(uniqEmails.find(res) == uniqEmails.end()) uniqEmails.insert(res);
//            uniqEmails[res] ++;
        }
        return uniqEmails.size();
    }
};

// use less memory, concise version, still 20ms:
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> uniqEmails;
        for( auto input: emails){
            int tail = input.size()-1, head = 0;
            while( tail >= 0 ){
                if( input[tail] != '@') tail--;
                else break;
            }
            string local = "";
            while( head < tail){
                if( input[head] == '+') break;
                if( input[head] != '.' || (input[head] == '.' && head == 0)) local += input[head];
                head ++;
            }
            local = local + input.substr(tail);
            if(uniqEmails.find(local) == uniqEmails.end()) uniqEmails.insert(local);
        }
        return uniqEmails.size();
    }
};