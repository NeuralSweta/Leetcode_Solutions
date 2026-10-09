class Solution {
public: 
    int helper(int r1,int r2,int c1,int n,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp){   
        int c2= r1+c1-r2;
        if(r1>=n ||r2>=n || c1>=n|| c2>=n)return INT_MIN; 
        if(grid[r1][c1]==-1 || grid[r2][c2]==-1)return INT_MIN;
        if(r1 == n-1 && c1 == n-1)return grid[r1][c1];
        int ans =grid[r1][c1];
        if(r1!=r2){
           ans +=grid[r2][c2];
        }
        if(dp[r1][c1][r2]!= INT_MIN)return dp[r1][c1][r2];
        int a=helper(r1,r2,c1+1,n,grid,dp);
        int b=helper(r1,r2+1,c1+1,n,grid,dp);
        int c=helper(r1+1,r2,c1,n,grid,dp);
        int d=helper(r1+1,r2+1,c1,n,grid,dp);
        return dp[r1][c1][r2]=ans+ max({a,b,c,d});
    }   
    int cherryPickup(vector<vector<int>>& grid) {
        int n= grid.size(); 
        int ans=0;
        int r1=0,c1=0,r2=0;
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(n,INT_MIN)));
        return max(0,helper(r1,r2,c1,n,grid,dp));  
    }
};