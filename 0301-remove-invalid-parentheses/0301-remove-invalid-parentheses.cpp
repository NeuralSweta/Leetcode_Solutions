
class Solution {
public:
    unordered_set<string> ans;
    unordered_set<string> st;
    int minDel = INT_MAX;

    void solve(string &s, int idx, string &curr, int bal, int del) {
        if (del > minDel) return;

        if (idx == s.size()) {
            if (bal == 0) {
                if (del < minDel) {
                    minDel = del;
                    ans.clear();
                }
                if (del == minDel) {
                    ans.insert(curr);
                }
            }
            return;
        }

        char ch = s[idx];

        // Case 1: Ordinary char
        if (ch != '(' && ch != ')') {
            curr.push_back(ch);
            solve(s, idx + 1, curr, bal, del);
            curr.pop_back();
            return;
        }

        // Case 2: Remove curr paren
        solve(s, idx + 1, curr, bal, del + 1);

        // Case 3: Keep the curr paren
        if (ch == '(') {
            curr.push_back(ch);
            solve(s, idx + 1, curr, bal + 1, del);
            curr.pop_back();
        } 
        else if (bal > 0) {
            curr.push_back(ch);
            solve(s, idx + 1, curr, bal - 1, del);
            curr.pop_back();
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        ans.clear();
        st.clear();
        minDel = INT_MAX;

        string curr = "";
        solve(s, 0, curr, 0, 0);

        return vector<string>(ans.begin(), ans.end());
    }
};
