class Solution {
public:
    int helper(int n,vector<int>&nums,int sum){
        if(n==0){
            if(nums[0]==0 && sum==0)return 2;
            if(sum==0 || nums[n]==sum)return 1;
            else return 0;
        }
         int nontake= helper(n-1,nums,sum);
         int take= 0;
         if(nums[n]<=sum)take=helper(n-1,nums,sum-nums[n]);
         return take+nontake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int totalSum= accumulate(nums.begin(),nums.end(),0);
        if((totalSum-target)%2!=0)return 0;
        int sum=(totalSum-target)/2;
         return helper(n-1,nums,sum);
    }
};