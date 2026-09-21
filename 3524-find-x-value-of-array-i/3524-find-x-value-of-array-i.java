class Solution {
    public long[] resultArray(int[] nums, int k) {
        long[] res = new long[k];
        long[] cnt = new long[k];
        for (int v : nums) {
            int m = v % k;
            long[] nxt = new long[k];
            nxt[m]++;                             
            for (int r = 0; r < k; r++) {
                nxt[(r * m) % k] += cnt[r];        
            }
            for (int r = 0; r < k; r++) res[r] += nxt[r];
            cnt = nxt;
        }
        return res;
    }
}