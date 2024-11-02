class Solution {
public:
    int solve(int row, int col, vector<vector<int>>&grid, int n, int m,vector<vector<int>>&dp){
        if(dp[row][col]!=-1)return dp[row][col];
        int moves =0;
        for(int i= -1;i<2;i++){

            int r=row+i;
            int c= col+1;
            if( r>=0 && c<m  && r<n && grid[r][c] > grid[row][col]){
                moves = max(moves, 1 + solve(r,c,grid, n, m,dp));
            }
        }
        return dp[row][col] = moves;
    }
    int maxMoves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int ans =0;
        for(int row=0;row<n;row++){
           ans= max(ans,solve(row,0,grid,n,m,dp));
        }
        return ans;
    }

};