class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    bool dfs(vector<vector<char>>& board , int i,int j, string &word,int indx){
        int n = board.size(),m = board[0].size();
        if(indx>= word.size())return true;
        if(i>=n || j>= m || i<0 || j<0 || board[i][j]!= word[indx])return false;
        char temp = board[i][j];
        board[i][j] = '.';
        for(int k  = 0;k<4;k++){
            int nx = i+dx[k],ny =j+dy[k];
            if(dfs(board,nx,ny,word,indx+1))return true;
            
        }
        board[i][j] = temp;
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        // do backtracking..
        int n = board.size(),m = board[0].size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(dfs(board,i,j,word,0))return true;
            }
        }
        return false;
    }
};