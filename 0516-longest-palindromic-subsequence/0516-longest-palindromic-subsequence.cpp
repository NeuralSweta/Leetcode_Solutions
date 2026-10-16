class Solution {
public:
    int helper(int i,int j,string &s,string &s2,vector<vector<int>>&dp){
        if(i<0||j<0)return 0;
         if(s[i]==s2[j])return 1+helper(i-1,j-1,s,s2,dp);
         if(dp[i][j]!=-1)return dp[i][j];
         return dp[i][j]=max(helper(i-1,j,s,s2,dp),helper(i,j-1,s,s2,dp));      
    }
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        string s2= s;
        reverse(s2.begin(),s2.end());
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return helper(n-1,n-1,s,s2,dp);
    }
};