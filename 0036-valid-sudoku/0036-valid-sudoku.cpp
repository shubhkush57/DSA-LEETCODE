class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        for(int i = 0;i<n;i++){
            // for each row check 
            vector<int>col(m+1,0);
            for(int j =0;j<m;j++){
                if(board[i][j] != '.' ){
                    if(col[board[i][j]-'0'] != 0)return false;
                    col[board[i][j]-'0']++;
                }
            
            }
        }
        for(int j =0;j<m;j++){
            // for each col
            vector<int>row(n+1,0);
            for(int i =0;i<n;i++){
                if(board[i][j] != '.' ){
                    if(row[board[i][j]-'0'] != 0)return false;
                    row[board[i][j]-'0']++;
                }
            
            }
        }
        // we need to think about the 
        int i = 0;
        while(i<m){
            int j = 0;
            while(j<m){
                vector<int>sq(m+1,0);
                for(int sx = i;sx<i+3;sx++){
                    for(int sy = j;sy<j+3;sy++){
                        if(board[sx][sy] != '.'){
                            if(sq[board[sx][sy]-'0'] >0){
                                return false;
                            }
                            sq[board[sx][sy]-'0']++;
                        }
                    }
                }
                j+=3;
            }
            i+= 3;
        }
        return true;
    }   
};