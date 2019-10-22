// 运行时间：142ms 占用内存：5044k
class Solution {
private:
    int cnt = 0;
    void mergeSort(vector<int>& data, int l, int r){
        if( l >= r ) return;
        int mid = l + (r-l)/2;
        mergeSort(data, l, mid);
        mergeSort(data, mid+1, r);
        // merge in-place
        vector<int> res;
        int p = l, q = mid+1;
        while( p <= mid && q <= r ){
            if( data[p] <= data[q] )
                res.push_back( data[p++] );
            else{
                cnt = cnt % 1000000007 + (mid-p+1) % 1000000007;//左部分:data[p]及其之后的元素都比data[q]大，要在此记录，因为q即将移走;且注意cnt会越界所以要在此时按题意取模
                res.push_back( data[q++] );
            }
        }
        while( p <= mid ) res.push_back( data[p++] );
        while( q <= r ) res.push_back( data[q++] );
        for(int i = l; i <= r; i++ )
            data[i] = res[i-l];
    }
public:
    int InversePairs(vector<int> data) { // merge sort
        mergeSort(data, 0, data.size()-1);
        return cnt % 1000000007;
    }
};