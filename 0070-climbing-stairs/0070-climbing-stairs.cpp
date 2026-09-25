class Solution {
public:
#define ll long long
    int climbStairs(int n) {
        vector<ll>dp(n+1,-1);
        dp[0]=1;
        dp[1]=2;
        for(auto i=2;i<n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n-1];
    }
    
};