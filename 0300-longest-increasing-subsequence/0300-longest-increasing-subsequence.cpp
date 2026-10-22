class Solution {
public:
    int helper(int i,int prevIdx,vector<int>& nums,vector<vector<int>>&dp){
        int n=nums.size();
        if(i==n)return 0;
        if(dp[i][prevIdx+1]!=-1)return dp[i][prevIdx+1];
        int take=0, nontake=0;
        if(prevIdx==-1||nums[prevIdx]<nums[i])take= 1+helper(i+1,i,nums,dp);
        nontake=helper(i+1,prevIdx,nums,dp);
        return dp[i][prevIdx+1]= max(take,nontake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return helper(0,-1,nums,dp);
    }
};