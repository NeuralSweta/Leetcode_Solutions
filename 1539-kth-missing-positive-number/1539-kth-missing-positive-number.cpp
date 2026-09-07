class Solution {
public:
    bool check(int missingCount,int k){
        if(missingCount>=k)return true;
        else return false;
    }
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int low=0,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int missingCount=arr[mid]-(mid+1);
            if(check(missingCount,k))high=mid-1;
            else low=mid+1;
        }
        return low+k;
    }
};