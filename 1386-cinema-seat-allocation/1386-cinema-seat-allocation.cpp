class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rowMask;
        
        for (auto& rs : reservedSeats) {
            int row = rs[0];
            int seat = rs[1];
            if (seat >= 2 && seat <= 9) {
                rowMask[row] |= (1 << seat);
            }
        }
        
        const int leftMask  = (1<<2)|(1<<3)|(1<<4)|(1<<5);
        const int midMask   = (1<<4)|(1<<5)|(1<<6)|(1<<7);
        const int rightMask = (1<<6)|(1<<7)|(1<<8)|(1<<9);
        
        long long total = 0;
        // Rows with no reservations at all
        total += 2LL * (n - rowMask.size());
        
        for (auto& [row, mask] : rowMask) {
            if ((mask & leftMask) == 0 && (mask & rightMask) == 0) {
                total += 2;
            } else if ((mask & leftMask) == 0 || (mask & midMask) == 0 || (mask & rightMask) == 0) {
                total += 1;
            }
        }
        
        return (int)total;
    }
};