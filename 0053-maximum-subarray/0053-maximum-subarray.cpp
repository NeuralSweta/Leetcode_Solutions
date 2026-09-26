class Solution {
public:
   int subSum(vector<int>&nums,int i,int current,int &best){
    int n= nums.size();
    if(i>=n)return best;
      current= max(nums[i], current+nums[i]);
      best= max(best,current);
      subSum(nums,i+1,current,best);
      return best;
   }

    int maxSubArray(vector<int>& nums) {
         int best=nums[0];
         return subSum(nums,0,0,best);
    }
};