class Solution {
public:
    void fxn(vector<vector<int>>&ds, vector<int>&v,vector<int>& nums, int i, vector<bool> &flag ){
       int n= nums.size();
       if(i==n){
        ds.push_back(v);
        return;
       }
       for(int j=0;j<n;j++){
        if(flag[j])continue;
        v.push_back(nums[j]);
        flag[j]= true;
        fxn(ds,v,nums,i+1,flag);
        flag[j]=false;
        v.pop_back();
       }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ds;
        vector<int>v;
        vector<bool>flag(nums.size(),false);
        fxn(ds,v,nums,0,flag);
        return ds;
    }
};