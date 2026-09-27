class Solution {
public:
    bool palindrome(string &t, int i, int j){
        int n=t.length();
        if(i>=j)return true;
        if(t[i]!=t[j])return false;
       return palindrome(t,i+1,j-1);
    }
    bool isPalindrome(string s) {
        string t;
        for(char ch:s)if(isalnum(ch))t+=tolower(ch);
        int n=t.length();
        return palindrome(t,0,n-1);
        
    }
};