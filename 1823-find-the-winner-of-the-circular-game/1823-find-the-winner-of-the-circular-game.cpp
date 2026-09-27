class Solution {
public:
     int winner(int n, int k){
        if(n == 1)return 0;  // return 0 as 0-based indexing
        return (winner(n - 1, k) + k) % n; // +k as next deletion starts after that,  %n as circular

    }
    int findTheWinner(int n, int k) {
        return winner(n, k) + 1;  // +1 in final answer as 0-based idx 

    }
};