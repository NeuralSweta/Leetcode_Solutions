class Solution {
    public int rob(int[] nums) {
        int n= nums.length;
        if(n==0)return 0;
        if(n==1)return nums[0];
        int[] dp1= new int[n];
        int[] dp2= new int[n];
        Arrays.fill(dp1,-1);
        Arrays.fill(dp2,-1);
        return Math.max(loot(0,nums,dp1,n-1),loot(1,nums,dp2,n));
    }
    public int loot(int i, int[] nums,int[] dp, int limit){
        if(i>=limit)return 0;
        if(dp[i]!=-1)return dp[i];
        int pick= nums[i]+ loot(i+2,nums,dp,limit);
        int skip= loot(i+1,nums,dp,limit);
        return dp[i]= Math.max(pick,skip);
    }
}