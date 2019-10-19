//运行时间：3ms 占用内存：460k
class Solution {
private:
    bool verify(vector<int>& s, int l, int r){
        if( l >= r ) return true;
        int i = r-1;
        while( i >= l && s[i] > s[r] ) i--; //i在第一个比root即s[r]小的元素处停下->左子树根，或直接越界->无左子树
        bool left = verify(s, l, i);
        bool right = verify(s, i+1, r-1);
        while( i >= l ){// check whether left tree has no element > root, since we may have not check因为在遇到第一个比root小的就停了
            if( s[i] > s[r] ) return false;
            else i--;
        }
        return left && right;
    }
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        int n = sequence.size();
        if( n == 0 ) return false; //当输入为空，输出为false；而helper函数里判断时，空树为true
        return verify(sequence, 0, n-1);
    }
};