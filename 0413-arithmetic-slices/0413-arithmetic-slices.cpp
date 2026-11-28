class Solution {
public:
    int LIS(vector<int>&nums,int i,vector<int>&dp){
        if(i<2)return 0;
        if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2])return dp[i]= 1+LIS(nums,i-1,dp);
        else return dp[i]=0;
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        int ans=0;
        for(int j=2;j<n;j++){
           ans += LIS(nums,j,dp);
        }
        return ans;
    }
};