class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n= nums.size();
        int totalSum= accumulate(nums.begin(),nums.end(),0);
        if(totalSum%2)return false;
        int target=totalSum/2;
        vector<vector<int>>dp(n,vector<int>(target+1,0));
        for(int i=0;i<n;i++)dp[i][0]=true;
        if(nums[0]<=target)dp[0][nums[0]]=true;
        for(int i=1;i<n;i++){
            for(int j=1;j<=target;j++){
                bool skip= dp[i-1][j];
                bool pick= false;
                if(j>=nums[i])pick=dp[i-1][j-nums[i]];
                dp[i][j]=pick||skip;
            }
        }     
     return dp[n-1][target];   
    }
};