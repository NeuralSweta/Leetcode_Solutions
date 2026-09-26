class Solution {
public:
   int subSum(vector<int>&nums,int i,int current,int &best,vector<int>&dp){
    int n= nums.size();
    if(i>=n)return best;
    if(dp[i]!=-1)return dp[i];
      current= max(nums[i], current+nums[i]);
      best= max(best,current);
      subSum(nums,i+1,current,best,dp);
      return dp[i]= best;
   }

    int maxSubArray(vector<int>& nums) {
         int best=nums[0];
         int n=nums.size();
         vector<int>dp(n+1,-1);
         return subSum(nums,0,0,best,dp);
    }
};