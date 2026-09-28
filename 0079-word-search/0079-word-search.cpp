class Solution {
public:
    bool checkWord(int i, int j,int k,int n,vector<vector<char>>& board, string& word){  
        if(k==n) return true;
        if(i<0 || i>=board.size()|| j<0 || j>=board[0].size())return false;
        if(board[i][j]!=word[k])return false;
        char temp=board[i][j];
        board[i][j]='#';
        bool found= 
        checkWord(i+1,j,k+1,n,board,word)||
        checkWord(i,j+1,k+1,n,board,word)||
        checkWord(i,j-1,k+1,n,board,word)||
        checkWord(i-1,j,k+1,n,board,word);
        board[i][j]=temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
         int n= word.size();
         for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                 if(checkWord(i,j,0,n,board,word))return true;
                }
            }
         }
         return false;
    }
};