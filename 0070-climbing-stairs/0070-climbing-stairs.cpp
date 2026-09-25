class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return helper(dp,n,0);
    }
    int helper(vector<int>&dp,int n,int i){
         if(i>n)return 0;
         if(i==n)return 1;
         if(dp[i]!=-1)return dp[i];
         return dp[i]=helper(dp,n,i+1)+helper(dp,n,i+2);
    }
};