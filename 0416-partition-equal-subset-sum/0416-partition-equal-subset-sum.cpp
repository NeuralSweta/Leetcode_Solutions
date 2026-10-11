class Solution {
public:
    bool helper(int n,int target,vector<int>&nums,vector<vector<int>>&dp){
        if(target==0)return true;
        if(n==0)return (nums[0]==target);
        if(dp[n][target]!=-1)return dp[n][target];
        bool skip= helper(n-1,target,nums,dp);
        bool pick= false;
        if(target>=nums[n])pick=helper(n-1,target-nums[n],nums,dp);
        return dp[n][target]=pick||skip;
        
    }
    bool canPartition(vector<int>& nums) {
        int n= nums.size()-1;
        int totalSum= accumulate(nums.begin(),nums.end(),0);
        if(totalSum%2)return false;
        int target=totalSum/2;
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return  helper(n,target,nums,dp);
    }
};