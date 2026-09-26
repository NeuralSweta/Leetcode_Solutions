class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        vector<int>earn(maxi+1); // store earn of a particular num (2,3,4)= (4,9,4)// then apply house robber on earn
        for(int ele:nums)earn[ele]+=ele;
        vector<int>dp(maxi+1,-1);
          dp[0]=earn[0];
          dp[1]=max(earn[0],earn[1]);
         for(int i=2;i<=maxi;i++){
            dp[i]=max(earn[i]+dp[i-2],dp[i-1]);
         }
      return dp[maxi];   
    }
};