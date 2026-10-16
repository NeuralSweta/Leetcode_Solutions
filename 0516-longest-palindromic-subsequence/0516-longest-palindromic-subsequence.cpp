class Solution {
public:
    int helper(int i,int j,string &s,string &s2,vector<vector<int>>&dp){
        if(i==0||j==0)return 0;
         if(s[i-1]==s2[j-1])return 1+helper(i-1,j-1,s,s2,dp);
         if(dp[i][j]!=-1)return dp[i][j];
         return dp[i][j]=max(helper(i-1,j,s,s2,dp),helper(i,j-1,s,s2,dp));      
    }
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        string s2= s;
        reverse(s2.begin(),s2.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return helper(n,n,s,s2,dp);
    }
};