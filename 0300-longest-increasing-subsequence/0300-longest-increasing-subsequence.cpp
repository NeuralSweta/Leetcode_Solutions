class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        //  for(int j=0;j<n;j++)dp[n][i]=0;
        for(int i=n-1;i>=0;i--){
            for(int prevIdx=i-1;prevIdx>=-1;prevIdx--){
                int take=0, nontake=0;
                nontake=dp[i+1][prevIdx+1];
                if(prevIdx==-1||nums[prevIdx]<nums[i])take= 1+dp[i+1][i+1];
                dp[i][prevIdx+1]= max(take,nontake);
            }
        }
        return dp[0][0];
    }
};