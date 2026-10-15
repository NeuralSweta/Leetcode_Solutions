class Solution {
public:
    int helper(int n,int amount,vector<int>&coins,vector<vector<int>>&dp){
        if(n==0) return (amount%coins[0]==0);
        if(dp[n][amount]!=-1)return dp[n][amount];
        int nontake=helper(n-1,amount,coins,dp);
        int take=0;
        if(coins[n]<=amount)take=helper(n,amount-coins[n],coins,dp);
        return dp[n][amount]=take+nontake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return helper(n-1,amount,coins,dp);
    }
};