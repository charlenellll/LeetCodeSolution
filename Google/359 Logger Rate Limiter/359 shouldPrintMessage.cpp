// 48 ms, beats 99.21%
// O(N) SPACE, O(1) TIME
// use an unordered_map

class Logger {
private:
    unordered_map<string, int> printed;
public:
    /** Initialize your data structure here. */
    Logger() {
        printed.clear();
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if( printed.find(message) != printed.end() && abs(printed[message] - timestamp) < 10) return false;
        else{
            printed[message] = timestamp;
            return true;
        }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */