class Solution {
public:
    void helper(int n, int l, int r,string s, vector<string> &ans){
        if(r==n){
            ans.push_back(s);
            return;
        }
        if(l<n)helper(n,l+1,r,s+"(",ans);
        if(l>r)helper(n,l,r+1,s+")",ans);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s="";
        helper(n,0,0,s,ans);
        return ans;
    }
};