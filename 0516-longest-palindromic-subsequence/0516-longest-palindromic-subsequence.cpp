class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        string s2= s;
        reverse(s2.begin(),s2.end());
        vector<int>prev(n+1),cur(n+1);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==s2[j-1])cur[j]=1+prev[j-1];
                else cur[j]=max(prev[j],cur[j-1]);
            }
            prev=cur;
        }
        return prev[n];
    }
};