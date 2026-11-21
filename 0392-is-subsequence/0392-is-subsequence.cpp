class Solution {
public:
    int helper(int i, int j,string &s,string &t,vector<vector<int>>&dp){
        if(i<0||j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==t[j]) return dp[i][j]= 1+helper(i-1,j-1,s,t,dp);
        return dp[i][j]=max(helper(i-1,j,s,t,dp),helper(i,j-1,s,t,dp));
    }
    bool isSubsequence(string s, string t) {
        int n=s.size(), m=t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int count=helper(n-1,m-1,s,t,dp);
        return count==n? true:false;
    }
};