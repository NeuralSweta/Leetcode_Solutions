class Solution {
public:
#define ll long long
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m= obstacleGrid.size();
        int n= obstacleGrid[0].size();
        vector<vector<ll>>dp(m+1,vector<ll>(n+1));
        for(int i=n-1;i>=0;i--){
            if(obstacleGrid[m-1][i]==0)dp[m-1][i]=1;
            else break;
        }
        for(int i=m-1;i>=0;i--){
            if(obstacleGrid[i][n-1]==0)dp[i][n-1]=1;
            else break;
        }
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                if(obstacleGrid[i][j]!=1)dp[i][j]=dp[i+1][j]+dp[i][j+1];
            }
        }
        return (int)dp[0][0];
    }
};