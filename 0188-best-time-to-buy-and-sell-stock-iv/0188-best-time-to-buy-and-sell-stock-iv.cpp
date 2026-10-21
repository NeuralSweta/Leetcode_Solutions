class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        for(int i=0;i<n;i++){
            for(int j=0;j<2;j++){
                dp[i][j][0]=0;
            }
        }
        for(int i=0;i<2;i++){
            for(int j=0;j<k;j++){
                dp[n][i][j]=0;
            }
        }
        for(int idx=n-1;idx>=0;idx--){
            for(int buy=0;buy<2;buy++){
                for(int i=k;i>0;i--){
                    int profit=0;
                    if(buy)profit=max((-prices[idx]+dp[idx+1][0][i]),dp[idx+1][1][i]);
                    else profit= max((prices[idx]+dp[idx+1][1][i-1]),dp[idx+1][0][i]);
                    dp[idx][buy][i]=profit;
                }
            }
        }
        return dp[0][1][k];
    }
};