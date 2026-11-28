class Solution {
public:
    int LIS(vector<int>&nums,int i){
        if(i<2)return 0;
        if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2])return 1+LIS(nums,i-1);
        else return 0;
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int j=2;j<n;j++){
           ans += LIS(nums,j);
        }
        return ans;
    }
};