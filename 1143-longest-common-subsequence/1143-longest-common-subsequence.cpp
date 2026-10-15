class Solution {
public:
    // int helper(int i, int j,string s1,string s2,vector<vector<int>>&dp){
    //    if(i==0 || j==0)return 0; 
    //    if(s1[i-1]==s2[j-1])return 1+helper(i-1,j-1,s1,s2,dp);
    //    if(dp[i][j]!=-1)return dp[i][j];
    //    int skip1=helper(i-1,j,s1,s2,dp);
    //    int skip2=helper(i,j-1,s1,s2,dp);
    //    return max(skip1,skip2);
    // }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m= text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
         for(int i=0;i<=n;i++)dp[i][0]=0;
         for(int i=0;i<=m;i++)dp[0][i]=0;
         for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1])dp[i][j]=1+(dp[i-1][j-1]);
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
         }
         return dp[n][m];
    }
};