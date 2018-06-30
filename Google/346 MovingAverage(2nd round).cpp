// after optimization, more concise code:
// 35 ms, beats 82.96%
class MovingAverage {
private:
    queue<int> q;
    int count;
    int capacity;
    int sum;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        capacity = size;
        count = 0;
        sum = 0;
    }

    double next(int val) {
        count ++;
        sum+=val;
        q.push(val);
        if( count > capacity ){
            sum -= q.front();
            q.pop();
        }
        return (double)sum/min(count, capacity);
    }
};

// Using queue: is more convenient than vector
// Original code:
// 37 ms, 49%

class MovingAverage {
private:
    queue<int> q;
    int count;
    int capacity;
    int sum;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        capacity = size;
        count = 0;
        sum = 0;
    }

    double next(int val) {
        count ++;
        if( count <= capacity ){
            sum+=val;
            q.push(val);
        }
        else{
            sum -= q.front();
            q.pop();
            sum += val;
            q.push(val);
        }
        return (double)sum/min(count, capacity);
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */