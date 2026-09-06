class Solution {
public:
   bool check(int h, long long time){
    if(time<=h)return true;
    return false;
   }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1;
        int high=0;
        int ans=-1;
        for(int i=0;i<n;i++) high= max(high,piles[i]);
        while(low<=high){
            int mid= low+(high-low)/2;
            long long totalTime=0;
            for(int i=0;i<n;i++){
               totalTime += ceil((double)piles[i]/mid);
            }
            if(check(h,totalTime)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};