class Solution {
public:
    int firstOccurance(vector<int>&nums,int target, int low,int high){
        int idx=-1;
        while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]==target){
           idx=mid;
           high=mid-1;
        }
        else if(nums[mid]>target){
            high=mid-1;
        }
        else low=mid+1;
     }
     return idx;
    }
    int lastOccurance(vector<int>&nums,int target, int low,int high){
        int idx=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                idx=mid;
                low=mid+1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else high=mid-1;
        }
        return idx;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>v(2);
        int n=nums.size();
        v[0]=firstOccurance(nums,target,0,n-1);
        v[1]=lastOccurance(nums,target,0,n-1);
        return v;
    }
};