class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>px(n),sx(n),ans(n);
        px[0]=1,sx[n-1]=1;
        for(int i=1;i<n;i++){
            px[i]=nums[i-1]*px[i-1];
        }
        for(int i=n-2;i>=0;i--){
            sx[i]=nums[i+1]*sx[i+1];
        }
        for(int i=0;i<n;i++){
            ans[i]=px[i]*sx[i];
        }
        return ans;
    }
};