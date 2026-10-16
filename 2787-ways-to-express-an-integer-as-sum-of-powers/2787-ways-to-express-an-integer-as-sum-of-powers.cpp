class Solution {
    long long MOD= 1e9+7;
public:
    int helper(int n,int x,int curr, vector<vector<int>>&dp) {
        if(n==0)return 1;
        if(n<0)return 0;
        if(dp[n][curr]!=-1)return dp[n][curr];
        int val= (int)pow(curr,x);
        if(val>n)return 0;
        int nontake = helper(n,x,curr+1,dp);
        int take = helper(n-val,x,curr+1,dp);
        return dp[n][curr]=(take + nontake)%MOD;
    }
    int numberOfWays(int n, int x) {
        vector<vector<int>>dp(n+1,vector<int>(n+2,-1));
        return helper(n,x,1,dp);
    }
};