class Solution {
public:
bool check(int x, int y){
  if(x<=(y/x))return true;
  return false;
}
    bool isPerfectSquare(int num) {
        int low=1, high=num;
        bool ans=false;
        while(low<=high){
            int mid= low+(high-low)/2;
            if(check(mid,num)){
                if(mid*mid==num)ans= true;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
};