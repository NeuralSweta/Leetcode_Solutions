class Solution {
public:
    int helper(vector<int>&nums,int i, vector<int>&earn, vector<int>&dp){
        int n= earn.size();
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        int pick=earn[i]+helper(nums,i+2,earn,dp);
        int skip= helper(nums,i+1,earn,dp);
        return dp[i]=max(pick,skip);
    }
    int deleteAndEarn(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        vector<int>earn(maxi+1); // store earn of a particular num (2,3,4)= (4,9,4)// then apply house robber on earn
        for(int ele:nums)earn[ele]+=ele;
        vector<int>dp(maxi+1,-1);
        return helper(nums,0,earn,dp);   
    }
};