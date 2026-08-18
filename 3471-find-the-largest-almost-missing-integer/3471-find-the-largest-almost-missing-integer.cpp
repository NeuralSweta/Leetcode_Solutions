class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int best = -1;
        unordered_set<int> distinct(nums.begin(), nums.end());
        
        for (int v : distinct) {
            int cnt = 0;
            for (int i = 0; i + k <= n; i++) {
                bool found = false;
                for (int j = i; j < i + k; j++) {
                    if (nums[j] == v) {
                        found = true;
                        break;
                    }
                }
                if (found) cnt++;
            }
            if (cnt == 1) best = max(best, v);
        }
        
        return best;
    }
};