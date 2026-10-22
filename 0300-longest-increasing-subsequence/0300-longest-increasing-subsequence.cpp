class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>ahead(n+1,0),cur(n+1,0);
        for(int i=n-1;i>=0;i--){
            for(int prevIdx=i-1;prevIdx>=-1;prevIdx--){
                int take=0, nontake=0;
                nontake=ahead[prevIdx+1];
                if(prevIdx==-1||nums[prevIdx]<nums[i])take= 1+ahead[i+1];
                cur[prevIdx+1]= max(take,nontake);
            }
            ahead=cur;
        }
        return ahead[0];
    }
};