class Solution {
public:
    void permute(int i, int n,vector<vector<int>>&ds,vector<int>&v,vector<int>& nums, vector<bool>&flag){
        if(i==n){
            ds.push_back(v);
            return;
        }
        for(int j=0;j<n;j++){
            if(flag[j])continue;
            if(j>0 && nums[j]==nums[j-1] && !flag[j-1])continue;
            v.push_back(nums[j]);
            flag[j]=true;
            permute(i+1,n,ds,v,nums,flag);
            flag[j]=false;
            v.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ds;
        vector<int>v;
        int n= nums.size();
        vector<bool>flag(n,false);
        permute(0,n,ds,v,nums,flag);
        return ds;
    }
};