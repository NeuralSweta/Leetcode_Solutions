class Solution {
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int>dp1(n+1,-1),dp2(n+1,-1);
        if(n==1)return nums[0];
        if(n==2)return max(nums[0],nums[1]);
        int num1=helper(nums,0,n-2,dp1);
        int num2=helper(nums,1,n-1,dp2);
        return max(num1,num2);
    }
    int helper(vector<int>&nums,int i,int n,vector<int>&dp){
        if(i>n)return 0;
        if(dp[i]!=-1)return dp[i];
        int pick= nums[i]+helper(nums,i+2,n,dp);
        int skip= helper(nums,i+1,n,dp);
        return dp[i]=max(pick,skip);
    }
};