class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ds;
        vector<int>v;
      combSum(0,candidates,target,ds,v);
      return ds;
    }
private:
void combSum(int i,vector<int>& candidates, int target,vector<vector<int>>&ds,vector<int>&v) {
    int n= candidates.size();
        if(i==n){
            if(target==0){
                ds.push_back(v);
            }
            return;
        }
        if(candidates[i]<=target){
        v.push_back(candidates[i]);
        combSum(i, candidates, target-candidates[i],ds,v);
        v.pop_back();
        }
        combSum(i+1,candidates, target,ds,v);
}

};