// Method 1: 3ms

class Solution {
private:
    vector<pair<int,int>> record;
    int maxDepth = 0;
    
    // get the depth
    void getDepth(const vector<NestedInteger>& nestedList, int depth){
        
        if( nestedList.size() == 0 ) return;
        maxDepth = max(maxDepth, depth);
        
        for( int i  = 0; i < nestedList.size(); i ++ ){
            if( nestedList[i].isInteger() )
                record.push_back( make_pair(nestedList[i].getInteger(), depth) );
            else
                getDepth(nestedList[i].getList(), depth+1);
        }
        return;
    }
    
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        
        getDepth(nestedList, 0);
        
        int sum = 0;
        for(auto n: record) 
            sum += n.first * (maxDepth - n.second + 1);
        return sum;
    }
};

// Method 2: 3ms

class Solution {
    
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        
        int unweighted = 0, weighted = 0;
        if( nestedList.size() == 0 ) return 0;
        while( nestedList.size() ){
            vector<NestedInteger> nextLevel;
            for( auto v: nestedList ){
                if( v.isInteger() )
                    unweighted += v.getInteger();
                else for(auto val: v.getList())
                    nextLevel.push_back( val );
            }
            weighted += unweighted;
            nestedList = nextLevel;
        }
        return weighted;
    }
};


// sample 0ms code

class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        if (nestedList.empty()) return 0;
        queue<NestedInteger> q;
        for (auto& item : nestedList) {
            q.push(item);
        }
        NestedInteger cur;
        int len, level = 0, result = 0;
        while (!q.empty()) {
            len = q.size();
            for (int i = 0; i < len; ++i) {
                cur = q.front();
                q.pop();
                if (cur.isInteger()) {
                    level += cur.getInteger();
                } else {
                    for (auto& item : cur.getList()) {
                        q.push(item);
                    }
                }
            }
            result += level;
        }
        return result;
    }
};

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */