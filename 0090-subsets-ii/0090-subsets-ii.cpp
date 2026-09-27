class Solution {
public:
    void sets(int i,vector<int>& nums,vector<vector<int>>&ds,vector<int>v, int n){
        ds.push_back(v);
       
        for(int idx=i;idx<n;idx++){
            if(idx>i && nums[idx]==nums[idx-1])continue;
            v.push_back(nums[idx]);
            sets(idx+1,nums,ds,v,n);
            v.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ds;
        vector<int>v;
        int n= nums.size();
        sets(0,nums,ds,v,n);
        return ds;
    }
};