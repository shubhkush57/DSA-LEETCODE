class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    bool findWord(vector<vector<char>>& board,string &word,int i,int j,int indx){
        int m = board.size(),n = board[0].size();
        if(indx>=word.size())return true;
        if(i>=m || i<0 || j>=n ||j<0 || board[i][j]!= word[indx])return false;
        char temp = board[i][j];
        board[i][j] = '.';
        for(int k = 0;k<4;k++){
            int nx = i+dx[k],ny = j+dy[k];
            if(findWord(board,word,nx,ny,indx+1))return true;
        }
        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        // we will be starting from each cell and backtrak
        int m = board.size(),n = board[0].size();
        for(int i = 0;i<m;i++){
            for(int j =0;j<n;j++){
                if(findWord(board,word,i,j,0))return true;
            }
        }
        return false;
    }
};