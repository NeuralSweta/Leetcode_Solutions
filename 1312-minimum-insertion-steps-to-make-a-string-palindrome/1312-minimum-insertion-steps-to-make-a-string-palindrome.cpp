class Solution {
public:
    int helper(int i, int j, string &s,string &t,vector<vector<int>>&dp){
        if(i<0||j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==t[j])return dp[i][j]=1+helper(i-1,j-1,s,t,dp);
        else return dp[i][j]=max(helper(i-1,j,s,t,dp),helper(i,j-1,s,t,dp));
    }
    int minInsertions(string s) {
        int n=s.size();
        string t=s;
        reverse(t.begin(),t.end());
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return n-helper(n-1,n-1,s,t,dp);
    }
};