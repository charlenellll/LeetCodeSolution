// Brutal-force
// 0 ms, beats 100%

class Solution {
public:
    string nextClosestTime(string time) {
        char original[4] = {time[0], time[1], time[3], time[4]};
        int digits[4] = {time[0]-'0', time[1]-'0', time[3]-'0', time[4]-'0'};
        sort(digits, digits+4);

        string res = "";
        for(int i = 0; i < 4; i++){
            if( digits[i] > (original[3]-'0'))
                return res + original[0] + original[1] + ":" + original[2] + char('0'+digits[i]);
        }
        original[3] = char('0'+digits[0]);
        for( int i = 0; i < 4; i++ ){
            if( digits[i] > (original[2]-'0') && digits[i] < 6)
                return res + original[0] + original[1] + ":" + char('0'+digits[i]) + original[3];
        }
        original[2] = char('0'+digits[0]);
        for( int i = 0; i < 4; i++){
            if( digits[i] > (original[1]-'0') && (original[0]-'0' < 2 || (original[0]-'0' == 2 && digits[i] <= 4)))
                return res + original[0] + char('0' + digits[i]) + ":" + original[2] + original[3];
        }
        original[1] = char('0'+digits[0]);
        for(int i = 0; i < 4; i++){
            if(digits[i] > (original[0]-'0') && digits[i] <= 2)
                return res + char('0'+digits[i]) + original[1] + ":" + original[2] + original[3];
        }
        original[0] = char('0'+digits[0]);
        return res+original[0]+original[1]+":"+original[2]+original[3];
    }
};


// sample code: MORE CONCISE than mine
// use upper_bound()

class Solution {
public:
    string nextClosestTime(string time) {
        set<char> s;
        for (int i = 0; i < time.size(); i++)
        {
            if (i == 2) continue;
            s.insert(time[i]);
        }
        
        vector<char> lmt = {'2', '9', ':', '5', '9'};
        if (time[0] == '2') lmt[1] = '3';
        for (int i = time.size() - 1; i >= 0; i--)
        {
            if (i == 2) continue;
            auto it = s.upper_bound(time[i]);
            if (it != s.end() && (*it) <= lmt[i])
            {
                time[i] = *it;
                return time;
            }
            time[i] = *(s.begin());
        }
        return time;
        
    }
};