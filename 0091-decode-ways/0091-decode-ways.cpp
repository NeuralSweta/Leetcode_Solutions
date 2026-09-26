class Solution {
public:
    bool valid(string s){
        if(s[0]=='0')return false;
        int num= stoi(s);
        return (num>0 && num<=26);       
    }
    int helper(string &s, int i,vector<int>&dp){
        int n= s.size();
        if(i==n)return 1;
        if(i>n)return 0;
        if(dp[i]!=-1)return dp[i];
        int take1=0, take2=0;
        if(i<=n && valid(s.substr(i,1)))take1= helper(s,i+1,dp);
        if(i<=n && valid(s.substr(i,2)))take2= helper(s,i+2,dp);
        return dp[i]=take1+take2;
    }
         
    int numDecodings(string s) {
        int n= s.size();
        vector<int>dp(n+1,-1);
       return helper(s,0,dp);
    }
};