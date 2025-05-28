class Solution {
public:
    int X[8] ={-1,-1,-1,0,0,1,1,1};
    int Y[8] = {-1,0,1,-1,1,-1,0,1};
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(),m = board[0].size();
        for(int i = 0;i<n;i++){
            for(int j= 0;j<m;j++){
                /// now see the 
                int count = 0;
                for(int k = 0;k<8;k++){
                    int nX =i+X[k],nY = j+Y[k];
                    if(nX>=0 && nY>=0 && nX<n && nY<m){
                        if(board[nX][nY] == 1 || board[nX][nY] == -1){
                            count++;
                        }
                    }
                }
                if((board[i][j] == 0 || board[i][j] == 2) ){
                    if(count == 3)
                    board[i][j] = 2;
                }
                else{
                    if(count<2) board[i][j] = -1;
                    else if(count ==2 || count == 3)  board[i][j] = 1;
                    else if(count>3)  board[i][j]  = -1;
                }
            }
        }

        for(int i = 0;i<n;i++){
            for(int j= 0;j<m;j++){
                /// now see the 
                if(board[i][j] == -1)board[i][j] = 0;
                else if(board[i][j] == 2)board[i][j] = 1;
            }
        }

        
    }
};