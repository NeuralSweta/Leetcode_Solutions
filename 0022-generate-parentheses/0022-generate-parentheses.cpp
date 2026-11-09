class Solution {
public:
    void helper(int l, int r,int n,vector<string>& ds,string s){
      if(r==n){
        ds.push_back(s);
        return;
      }
      if(l<n) helper(l+1,r,n,ds,s+'(');
      if(r<l) helper(l,r+1,n,ds,s+')');
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ds;
        helper(0,0,n,ds,"");
        return ds;
    }
};