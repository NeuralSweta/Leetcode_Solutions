class Solution {
public:
    bool check(int count,int cows){
        return count>=cows;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n=position.size();
        int low=1;
        int high= position[n-1]-position[0];
        while(low<=high){
            int mid=low+(high-low)/2;
            int count=1,lastPos=position[0];
            for(int ele:position){
                if(ele-lastPos>=mid){
                    count++;lastPos=ele;
                }
            }
            if(check(count,m))low=mid+1;
            else high=mid-1;
        }
        return high;
    }
};