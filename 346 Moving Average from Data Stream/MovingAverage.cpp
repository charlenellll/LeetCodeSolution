// Personally I suggest using queue. It's more direct, and simple
// 35 ms, 46.06%

class MovingAverage {
private:
    queue<int> q;
    int sz;
    int count;
    double sum;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        sz = size;
        count = 0;
        sum = 0;
    }
    
    double next(int val) {
        count ++;
        // Important!! Notice the edge! when count == sz, we don't need to pop out the first element!
        if( count <= sz ){ 
            sum += val;
            q.push( val );
            return sum / count;
        }
        else{ // count > sz
            sum += val;
            q.push(val);
            int out = q.front();
            q.pop();
            sum -= out;
            return sum / sz;
        }
    }
};

// Optimized solution 1: using queue
// just combined the instructions together and make it more concise
// It is not faster. Just shorter in lines. The above one is more direct and we can see the logic more clearly.

class MovingAverage {
private:
    queue<int> q;
    int sz;
    int count;
    double sum;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        sz = size;
        count = 0;
        sum = 0;
    }
    
    double next(int val) {
        count ++;
        sum += val;
        q.push( val );
        if(count > sz){        
            sum -= q.front();
            q.pop();
        }
        return sum / min(count, sz);
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */

// queue is more direct, while vector needs delicate thinking
// Solution 2:
// the fastest sample code is using vector, while it is not faster as far as my code runs

class MovingAverage {
private:
    vector<int> window;
    int sz;
    double sum;
    int index;
    int count;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        sz = size;
        sum = 0;
        window = vector<int>(size, 0);
        index = 0;
        count = 0;
    }

    double next(int val) {
        count ++;
        sum += val;
        index++;
        // this is the convenient way for sliding the index in the fixed window
        index = index % sz;
        sum -= window[index];
        window[index] = val;
        return sum / min(count, sz);
    }
};

// Optimized version of solution 2:

class MovingAverage {
private:
    vector<int> window;
    int sz;
    double sum;
    int index;
    int count;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        sz = size;
        sum = 0;
        window = vector<int>(size, 0);
        index = 0;
        count = 0;
    }

    double next(int val) {
        count ++;
        // Notice the order of these calculations!!
        sum = sum - window[index] + val;
        window[index++] = val;
        index = index % sz;        
        return sum / min(count, sz);
    }
};