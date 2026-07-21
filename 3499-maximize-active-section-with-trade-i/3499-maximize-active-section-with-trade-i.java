import java.util.*;
class Solution {
    public int maxActiveSectionsAfterTrade(String s) {
        int n = s.length();
        String t = "1" + s + "1";
        int m = t.length();
        List<int[]> blocks = new ArrayList<>();
        int i = 0;
        while (i < m) {
            int j = i;
            char c = t.charAt(i);
            while (j < m && t.charAt(j) == c) j++;
            blocks.add(new int[]{c - '0', j - i});
            i = j;
        }

        int k = blocks.size();
        int T = 0;
        for (char c : s.toCharArray()) if (c == '1') T++;
        if (k < 5) {
            return T; 
        }
        int[][] top = new int[3][2];
        for (int[] arr : top) { arr[0] = -1; arr[1] = -1; }

        for (int idx = 0; idx < k; idx++) {
            if (blocks.get(idx)[0] == 0) {
                int size = blocks.get(idx)[1];
                if (size > top[0][0]) {
                    top[2] = top[1];
                    top[1] = top[0];
                    top[0] = new int[]{size, idx};
                } else if (size > top[1][0]) {
                    top[2] = top[1];
                    top[1] = new int[]{size, idx};
                } else if (size > top[2][0]) {
                    top[2] = new int[]{size, idx};
                }
            }
        }
        int best = 0;
        for (int idx = 1; idx <= k - 2; idx++) {
            if (blocks.get(idx)[0] == 1) { 
                int a = blocks.get(idx)[1];
                int p = blocks.get(idx - 1)[1];
                int q = blocks.get(idx + 1)[1]; 
                int leftIdx = idx - 1;
                int rightIdx = idx + 1;
                int candidateA = p + q;
                int bestOther = -1;
                for (int[] arr : top) {
                    if (arr[1] != -1 && arr[1] != leftIdx && arr[1] != rightIdx) {
                        bestOther = arr[0];
                        break; 
                    }
                }
                int candidateB = (bestOther == -1) ? Integer.MIN_VALUE : bestOther - a;

                best = Math.max(best, Math.max(candidateA, candidateB));
            }
        }

        return T + best;
    }
}