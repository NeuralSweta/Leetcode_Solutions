class Solution {
public:
   void subSum(vector<int>&nums,int i,int current, int &best){
    int n= nums.size();
    if(i>=n)return ;
      current= max(nums[i], current+nums[i]);
      best= max(best,current);
      subSum(nums,i+1,current,best);
   }

    int maxSubArray(vector<int>& nums) {
        int best=nums[0];
          subSum(nums,0,0,best);
          return best;
    }
};