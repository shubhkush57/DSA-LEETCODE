class Solution {
public:
    int dx[4]= {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    int solve(vector<vector<int>>& matrix,int i,int j,vector<vector<int>>&dp){
       int m = matrix.size(),n = matrix[0].size();
       if(i>=m || j>=n || i<0 || j<0)return 0;
       if(dp[i][j] != -1)return dp[i][j];
       int ans = 1;
       for(int k = 0;k<4;k++){
          int nx = i+dx[k],ny = j+dy[k];
          if(nx<m && ny<n && nx>=0 && ny>=0 && matrix[nx][ny]>matrix[i][j]){
            ans = max(ans,1+solve(matrix,nx,ny,dp));
          }
       }

       return dp[i][j] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(),n = matrix[0].size();
        int ans = 0;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                ans = max(ans,solve(matrix,i,j,dp));
            }
        }
        return ans;
    }
};