// Optimization: 33ms 99.39%
// 1. Use unordered_map since the order of map doesn't matter here
// 2. terminal the loop earlier by checking if the value is < 2*minVal or > 2*maxVal of the map

class TwoSum {
private:
    unordered_map<int,int> record;
    int _min, _max;
public:
    /** Initialize your data structure here. */
    TwoSum() {
        record.clear();
        _min = INT_MAX, _max = INT_MIN;
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        record[number]++;
        if( number < _min ) _min = number;
        if( number > _max ) _max = number;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        if( value < _min*2 || value > _max*2 ) return false;
        for( unordered_map<int,int>::iterator p = record.begin(); p != record.end(); p++ ){
            if ( p->second > 1 && value == 2 * p->first )
                return true;
            if( record.find(value - p->first) != record.end() && value != 2 * p->first)
                return true;
        }
        return false;
    }
};


// first version: really slow


class TwoSum {
private:
    map<int,int> record;
public:
    /** Initialize your data structure here. */
    TwoSum() {
        record.clear();
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        record[number]++;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        
        for( map<int,int>::iterator p = record.begin(); p != record.end(); p++ ){        
            if( record.find(value - p->first) != record.end() && value != 2 * p->first)
                return true;
            if ( p->second > 1 && value == 2 * p->first )
                return true;
        }
        return false;
    }
};


// sample 33ms code

class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {
        imap.clear();
        _min=INT_MAX, _max=INT_MIN, num=0;
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        imap[number]++;
        if(number<_min)_min=number;
        if(number>_max)_max=number;
        num++;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        if(num<2)return false;
        if(2*_min>value || 2*_max<value)return false;
        
        for(auto e:imap)
        {
            if(2*e.first==value && e.second>=2)return true;
            else if(2*e.first!=value && imap.find(value-e.first)!=imap.end())return true;
        }
        return false;
    }
private:
    unordered_map<int, int> imap;
    int _min, _max, num;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */