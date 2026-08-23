class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int half = n / 2;
        int sum1 = 0, sum2 = 0, q1 = 0, q2 = 0;
        for (int i = 0; i < n; i++) {
            char c = num[i];
            if (i < half) {
                if (c == '?') q1++;
                else sum1 += c - '0';
            } else {
                if (c == '?') q2++;
                else sum2 += c - '0';
            }
        }
        int q = q1 + q2;
        if (q % 2 == 1) return true; 
        int diff = (sum1 - sum2) + 9 * (q1 - q2) / 2;
        return diff != 0; 
    }
};