// 1. Original quick sort: 只有一个移动指针i, i左侧为分好的区域，从i开始往右为未划分区域
// 64 ms, faster than 69.21%
class Solution {
private:
    void quicksort(vector<int>& nums, int l, int r){//[l..lt] <= v, [lt+1..i-1] > v, [i..r] unknown 
        if( l >= r ) return;
        int pivot = nums[l], lt=l; 
        // partition
        for(int i = l+1; i <= r; i++){ //l...lt | lt+1 ...i-1| i....r
            if( nums[i] <= pivot )
                swap(nums[i], nums[++lt]);// then i++
            // else i++
        }
        swap( nums[l], nums[lt] ); //nums[lt] <= (most likely < ) nums[l] so we need to put nums[l] to its right place
        quicksort(nums, l, lt-1);
        quicksort(nums, lt+1, r);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        quicksort(nums, 0, nums.size()-1);
        return nums;
    }
};

// 2. Quick sort 2-ways:有两个移动指针ij从两边逼近，包括i的左侧为<=v，包括j的右侧为>=v
// 60 ms, faster than 91.11% 
class Solution {
private:
    void quicksort(vector<int>& nums, int l, int r ){// [l..i-1]<= v, [i..j]unknown, [j+1..r] >= v
        if( l >= r ) return;
        int i = l+1, j = r, v=nums[l];// initial nums[l]=v, so i start from l+1
        while( true ){//i <= j也行，但当心，记得一定要取等！不然会漏swap
            while( i <= r && nums[i] <= v ) i++;//i停在从左到右第一个>v处
            while( j >= l+1 && nums[j] >= v ) j--;//j停在从右到左第一个<v处
            if( i >= j ) break;
            swap(nums[i], nums[j]);
            i++, j--;
        }
        swap(nums[l], nums[j]); //i停在从左到右第一个>v处，j停在从右到左第一个<v处
        quicksort(nums, l, j-1);
        quicksort(nums, j+1, r);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        quicksort(nums, 0, nums.size()-1);
        return nums;
    }
};

// 3. Quick sort 3-ways：有三个指针，分为<v,=v,未知,>v四个部分，有lt,i,gt三个指针
// 60 ms, faster than 91.11%
class Solution {
private:
    void quicksort(vector<int>& nums, int l, int r){//[l+1..lt] <v, [lt+1..i-1] ==v, [i..gt-1] unknown, [gt..r] >v
        if( l >= r ) return;
        int lt=l, gt=r+1, i=l+1, v=nums[l];
        while( i < gt ){//由以上定义，出循环时i=gt
            if( nums[i] < v ) swap(nums[i++], nums[++lt] );
            else if( nums[i] == v ) i++;
            else swap(nums[i], nums[--gt]);
        }
        swap(nums[l], nums[lt]); //lt最后指向<v的从左到右最后一个元素
        quicksort(nums, l, lt-1);
        quicksort(nums, gt, r);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        quicksort(nums, 0, nums.size()-1);
        return nums;
    }
};

// 注意只要涉及到quicksort就可以加一个优化：随机取pivot！！！
swap( arr[l], arr[rand()%(r-l+1)+l] );

// 4. Merge sort 比前面三种多个O(n) space，slow but这里权当复习排序写法
// 148 ms, faster than 13.30%
class Solution {
private:
    void mergesort(vector<int>& nums, int l, int r){
        if( l >= r ) return;
        int mid = l + (r-l)/2;
        mergesort(nums, l, mid);
        mergesort(nums, mid+1, r);
        // merge
        vector<int> aux;
        for(int i = l; i <= r; i++)
            aux.push_back(nums[i]);
        int p = 0, q = mid+1-l, i=l;
        while( p <= mid-l && q <= r-l ){
            if( aux[p] <= aux[q] )
                nums[i++] = aux[p++];
            else
                nums[i++] = aux[q++];
        }
        // 比较后剩余部分
        while( p <= mid-l ) nums[i++] = aux[p++];
        while( q <= r-l ) nums[i++] = aux[q++];
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums, 0, nums.size()-1);
        return nums;
    }
};
