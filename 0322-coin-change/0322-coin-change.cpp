class Solution {
public:
    int helper(int n,vector<int>& coins, int amount, vector<vector<int>>&dp){
       if(n==0){
        if(amount%coins[n]==0)return amount/coins[n];
        else return 1e9;
       }
       if(dp[n][amount]!=-1)return dp[n][amount];
       int nontake=helper(n-1,coins,amount,dp);
       int take=1e9;
       if(amount>=coins[n])take=1+helper(n,coins,amount-coins[n],dp);
       return dp[n][amount]=min(take,nontake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans= helper(n-1,coins,amount,dp);
        return (ans>=1e9)? -1:ans;
    }
};