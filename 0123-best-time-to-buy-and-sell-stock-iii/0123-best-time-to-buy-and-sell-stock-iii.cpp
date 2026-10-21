class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>next(2,vector<int>(3,0));
        vector<vector<int>>cur(2,vector<int>(3,0));
        //  for(int i=0;i<n;i++){
        //     for(int j=0;j<2;j++){
        //         dp[i][j][0]=0;
        //     }
        // }
        // for(int i=0;i<2;i++){
        //     for(int j=0;j<3;j++){
        //         dp[n][i][j]=0;
        //     }
        // }
        for(int idx=n-1;idx>=0;idx--){
            for(int j=0;j<2;j++){
                for(int k=1;k<3;k++){
                     int profit=0;
                     if(j)profit=max((-prices[idx]+next[0][k]),next[1][k]);
                     else profit=max((prices[idx]+next[1][k-1]),next[0][k]);
                     cur[j][k]=profit;
                }
            }
            next=cur;
        }
        return cur[1][2];
    }
};