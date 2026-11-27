class Solution {
public:
    int helper(vector<int>&nums, int i,vector<int>&dp){
       int ans=1;
       for(int j=0;j<i;j++){
        if(dp[i]!=-1)return dp[i];
        if(nums[i]>nums[j])ans=max(ans,helper(nums,j,dp)+1);
       }
       return dp[i]=ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int ans=1;
        vector<int>dp(n,-1);
        for(int i=0;i<n;i++){
           ans= max(ans, helper(nums,i,dp));
        }
        return ans;
    }
};