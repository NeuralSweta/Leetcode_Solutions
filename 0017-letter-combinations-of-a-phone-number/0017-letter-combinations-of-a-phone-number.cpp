class Solution {
public:
    void fxn(vector<string>&ds,vector<string>&v,string &digits, int i, string current){
        int n=digits.size();
        if(i==n){
            ds.push_back(current);
            return;
        }
        for(char ch: v[digits[i]-'0']){
            current.push_back(ch);
            fxn(ds,v,digits,i+1,current);
            current.pop_back();
        }
        
    }
    vector<string> letterCombinations(string digits) {
        vector<string>v={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
           vector<string>ds;
           fxn(ds,v,digits,0, "");
           return ds;
    }
};