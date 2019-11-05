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

// 2-nd time practice
class Solution {
private:
    long long cnt = 0;
    void mergesort(vector<int>& nums, int l, int r){
        if( l >= r ) return;
        int mid = l + (r-l)/2;
        mergesort(nums, l, mid);
        mergesort(nums, mid+1, r);
        // merge
        vector<int> aux;
        for(int i = l; i <= r; i++ )
            aux.push_back( nums[i] );
        int p = 0, q = mid+1-l, i=l;
        while( p <= mid-l && q <= r-l ){
            if( aux[p] <= aux[q] )
                nums[i++] = aux[p++];
            else{ // aux[p] > aux[q],统计逆序对:左半部分p后面的都比q大
                cnt += mid-l-p+1;
                nums[i++] = aux[q++];
            }
        }
        while( p <= mid-l ) nums[i++] = aux[p++];
        while( q <= r-l ) nums[i++] = aux[q++];
    }
public:
    int InversePairs(vector<int> data) {
        mergesort(data, 0, data.size()-1);
        return cnt % 1000000007;
    }
};