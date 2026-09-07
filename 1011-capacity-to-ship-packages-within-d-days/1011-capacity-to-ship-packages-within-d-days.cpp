class Solution {
public:
    bool check(int days, int reqDays){
        if(reqDays<=days)return true;
        else return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        while(low<=high){
            int mid=low+(high-low)/2;
            int reqDays=1, load=0;
            for(int ele:weights){
               if(load+ele>mid){
                reqDays++;
                load=ele;
               }
               else load+=ele;
            }
            if(check(days,reqDays))high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};