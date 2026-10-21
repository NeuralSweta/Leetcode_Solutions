class Solution {
public:
    int helper(int idx,int buy,vector<int>& prices, int fees, vector<vector<int>>&dp){
        int n=prices.size();
        if(idx==n)return 0;
        if(dp[idx][buy]!=-1)return dp[idx][buy];
        int profit=0;
        if(buy)profit=max((-prices[idx]+helper(idx+1,0,prices,fees,dp)),helper(idx+1,1,prices,fees,dp));
        else profit=max((prices[idx]-fees+helper(idx+1,1,prices,fees,dp)),helper(idx+1,0,prices,fees,dp));
        return dp[idx][buy]= profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return helper(0,1,prices,fee,dp);
    }
};