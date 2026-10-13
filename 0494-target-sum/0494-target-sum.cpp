class Solution {
public:
    int helper(int n,vector<int>&nums,int sum,vector<vector<int>>&dp){
        if(n==0){
            if(nums[0]==0 && sum==0)return 2;
            if(sum==0 || nums[n]==sum)return 1;
            else return 0;
        }
        if(dp[n][sum+1000]!=-1)return dp[n][sum+1000];
         int nontake= helper(n-1,nums,sum,dp);
         int take= 0;
         if(nums[n]<=sum)take=helper(n-1,nums,sum-nums[n],dp);
         return dp[n][sum+1000]=take+nontake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int totalSum= accumulate(nums.begin(),nums.end(),0);
        if((totalSum-target)%2!=0)return 0;
        int sum=(totalSum-target)/2;
        vector<vector<int>>dp(n+1,vector<int>(2002,-1));
         return helper(n-1,nums,sum,dp);
    }
};