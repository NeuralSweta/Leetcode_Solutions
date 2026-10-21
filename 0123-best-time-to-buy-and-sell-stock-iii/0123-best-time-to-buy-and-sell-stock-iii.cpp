class Solution {
public:
    // int helper(int idx,int buy,int cap,vector<int>& prices, vector<vector<vector<int>>>&dp){
    //     int n=prices.size();
    //     if(cap==0||idx==n)return 0;
    //     if(dp[idx][buy][cap]!=-1)return dp[idx][buy][cap];
    //     int profit=0;
    //     if(buy)profit=max((-prices[idx]+helper(idx+1,0,cap,prices,dp)),helper(idx+1,1,cap,prices,dp));
    //     else profit=max((prices[idx]+helper(idx+1,1,cap-1,prices,dp)),helper(idx+1,0,cap,prices,dp));
    //     return dp[idx][buy][cap]=profit;
    // }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
         for(int i=0;i<n;i++){
            for(int j=0;j<2;j++){
                dp[i][j][0]=0;
            }
        }
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                dp[n][i][j]=0;
            }
        }
        for(int idx=n-1;idx>=0;idx--){
            for(int j=0;j<2;j++){
                for(int k=1;k<3;k++){
                     int profit=0;
                     if(j)profit=max((-prices[idx]+dp[idx+1][0][k]),dp[idx+1][1][k]);
                     else profit=max((prices[idx]+dp[idx+1][1][k-1]),dp[idx+1][0][k]);
                     dp[idx][j][k]=profit;
                }
            }
        }
        return dp[0][1][2];
    }
};