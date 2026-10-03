class Solution {
public:
    int path(int i, int j, int m, int n, vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(i==0 && j==0)return grid[i][j];
        if(i==0)return grid[i][j]+path(0,j-1,m,n,grid,dp);
        if(j==0)return grid[i][j]+path(i-1,0,m,n,grid,dp);
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=grid[i][j]+min(path(i-1,j,m,n,grid,dp),path(i,j-1,m,n,grid,dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m= grid.size();
        int n= grid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return path(m-1,n-1,m,n,grid,dp);
    }
};