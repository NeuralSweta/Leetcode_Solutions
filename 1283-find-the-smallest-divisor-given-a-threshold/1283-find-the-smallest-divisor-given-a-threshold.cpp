#define ll long long
class Solution {
public:
    bool check(ll sum,int threshold){
        if(sum<=threshold)return true;
        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1, high=0;
        for(int ele:nums)high=max(high,ele);
        while(low<=high){
            ll mid= low+(high-low)/2;
            ll sum=0;
            for(ll ele:nums)sum+= ceil((double)ele/mid);
            if(check(sum,threshold))high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};