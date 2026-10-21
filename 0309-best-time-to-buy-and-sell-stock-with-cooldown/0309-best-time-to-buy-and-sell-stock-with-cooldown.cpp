class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size(); 
        vector<int>ahead1(2,0),ahead2(2,0),cur(2,0);
        for(int idx=n-1;idx>=0;idx--){
            for(int buy=0;buy<2;buy++){
                int profit=0;
                if(buy)profit=max((-prices[idx]+ahead1[0]),ahead1[1]);
                else profit=max((prices[idx]+ahead2[1]),ahead1[0]);
                cur[buy]=profit;
            }
            ahead2=ahead1;
            ahead1=cur;
        }
        return ahead1[1];
    }
};