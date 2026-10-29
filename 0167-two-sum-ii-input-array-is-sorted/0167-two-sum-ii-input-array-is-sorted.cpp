class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        for(int i=0;i<n;i++){
          int low=i+1, high=n-1;
          int req=target-numbers[i];
          while(low<=high){
            int mid=low+(high-low)/2;
            if(numbers[mid]==req){
            return {i+1,mid+1};
            }
            else if(numbers[mid]>req)high=mid-1;
            else low=mid+1;
          }
        }
        return {};
    }
};