class Solution {
public:
int helper(int idx,int buy,int k, vector<int>& prices,vector<vector<vector<int>>>&dp){
    int n=prices.size();
    if(k==0||idx==n)return 0;
    if(dp[idx][buy][k]!=-1)return dp[idx][buy][k];
    int profit=0;
    if(buy)profit=max((-prices[idx]+helper(idx+1,0,k,prices,dp)),helper(idx+1,1,k,prices,dp));
    else profit= max((prices[idx]+helper(idx+1,1,k-1,prices,dp)),helper(idx+1,0,k,prices,dp));
    return dp[idx][buy][k]=profit;
}
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return helper(0,1,k,prices,dp);
    }
};