class Solution {
public:
    int check(vector<int>& bloomDay, long long day, long long m, long long k){
        int count=0;
        int noOfB=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=day)count++;
             else{
             noOfB +=count/k;
             count=0;
             } 
        }
        noOfB+= (count/k);
        if(noOfB >=m)return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, long long m, long long k) {
        if(m*k>bloomDay.size())return -1;
        int low=INT_MAX,high=INT_MIN;
        for(int ele:bloomDay)low=min(low,ele);
        for(int ele:bloomDay)high=max(high,ele);
        while(low<=high){
            long long mid= low+(high-low)/2;
            if(check(bloomDay,mid,m,k))high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};