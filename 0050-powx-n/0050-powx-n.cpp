class Solution {
public:
#define ll long long
    double power(double x, ll n){
        double ans=1;
        while(n>0){
        if( n&1){
          ans= ans*x;
        }
        x*=x;
        n>>=1;
        }
        return ans;
    }
    double myPow(double x, int N) {
        ll n = N;
        if(n<0){
            n = -n;
            x=1/x;
        }
        return  power(x,n);      
    }
};