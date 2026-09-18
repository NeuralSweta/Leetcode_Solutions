class Solution {
public:
    void makeSubset(int i,vector<int>&nums,vector<vector<int>>&ds,vector<int>&v){
        int n=nums.size();
        if(i==n){
            ds.push_back(v);
            return;
        }
        v.push_back(nums[i]);
        makeSubset(i+1,nums,ds,v);
        v.pop_back();
        makeSubset(i+1,nums,ds,v);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ds;
        vector<int>arr;
        makeSubset(0,nums,ds,arr);
        return ds;
    }
};