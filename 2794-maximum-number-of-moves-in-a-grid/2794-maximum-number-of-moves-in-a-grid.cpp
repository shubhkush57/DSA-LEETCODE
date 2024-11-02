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
        int maxi=0;

        vector<vector<int>>dp(n,vector<int>(m,0));

         for(int j=m-2;j>=0;j--){
           for(int i = 0;i<n;i++){

                int x=0;
                if(i+1<n && j+1<m && grid[i][j] < grid[i+1][j+1]) x= 1+dp[i+1][j+1];
                if(j+1<m && grid[i][j+1]> grid[i][j]) x= max(x,1+dp[i][j+1]);
                if(i-1>=0 && j+1 <m && grid[i-1][j+1]>grid[i][j])x =max(x,1+ dp[i-1][j+1]);
                dp[i][j]=  x;

        }
        }
        for(int i=0;i<n;i++){
            maxi=max(maxi,dp[i][0]);
        }
     return maxi;
    }

    

};