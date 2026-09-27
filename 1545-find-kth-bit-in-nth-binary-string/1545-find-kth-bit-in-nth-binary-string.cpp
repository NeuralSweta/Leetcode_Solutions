class Solution {
public:
    char findKthBit(int n, int k) {
        if(n==1)return '0';
        int mid= 1<<(n-1);     // 2^n-1
        if(k==mid)return '1';
        if(k<mid) return findKthBit(n-1,k);
        char ans= findKthBit(n-1, (1<<n)-k); // n=4, 1<<n= 16, 16-k = 5(as find ans of right half in left half )
        return ans=='0'?'1':'0';
        
    }
};