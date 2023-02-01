class Solution {
public:
    bool solve(vector<vector<int>>&grid,int i,int j,vector<vector<int>>&vis){
        vis[i][j] = true;
        int m = grid.size();
        int n = grid[0].size();
        if(i == m-1 && j == n-1){
            return true;
        }
        bool ans = false;
        if(grid[i][j] == 1){
            // to left it mens left cell should have right path
            int nx = j-1;
            int ny = i;
            if(nx >=0 && ny >=0 && nx <n && ny <m && vis[ny][nx] == false && (grid[ny][nx] == 1 || grid[ny][nx] == 4 || grid[ny][nx] == 6)){
                ans = ans || solve(grid,ny,nx,vis);
            }
            // to right should have left
            nx = j+1;
            ny = i;
            if(nx >=0 && ny >=0 && nx <n && ny <m && vis[ny][nx] == false && (grid[ny][nx] == 1 || grid[ny][nx] == 3 || grid[ny][nx] == 5)){
                ans = ans || solve(grid,ny,nx,vis);
            }
        }
        else if(grid[i][j] == 2){
            int nx = j;
            int ny = i-1;
            // to upper should have lower
            if(nx >=0 && ny >=0 && nx <n && ny <m && vis[ny][nx] == false && (grid[ny][nx] == 2 || grid[ny][nx] == 3 || grid[ny][nx] == 4)){
                ans = ans || solve(grid,ny,nx,vis);
            }
            nx = j;
            ny = i+1;
            // should have upper
            if(nx >=0 && ny >=0 && nx <n && ny <m && vis[ny][nx] == false && (grid[ny][nx] == 2 || grid[ny][nx] == 6 || grid[ny][nx] == 5)){
                ans = ans || solve(grid,ny,nx,vis);
            }
        }
         else if(grid[i][j] == 3){
            int nx = j-1;
            int ny = i;
             // should have right
            if(nx >=0 && ny >=0 && nx <n && ny <m && vis[ny][nx] == false && (grid[ny][nx] == 1 || grid[ny][nx] == 4 || grid[ny][nx] == 6)){
                ans = ans || solve(grid,ny,nx,vis);
            }
            nx = j;
            ny = i+1;
             // should have upper
            if(nx >=0 && ny >=0 && nx <n && ny <m && vis[ny][nx] == false  && (grid[ny][nx] == 2 || grid[ny][nx] == 6 || grid[ny][nx] == 5)){
                ans = ans || solve(grid,ny,nx,vis);
            }
        }
        else if(grid[i][j] == 4){
            int nx = j+1;
            int ny = i;
            // should have left
            if(nx >=0 && ny >=0 && nx <n && ny <m && vis[ny][nx] == false && (grid[ny][nx] == 1 || grid[ny][nx] == 3 || grid[ny][nx] == 5)){
                ans = ans || solve(grid,ny,nx,vis);
            }
            nx = j;
            ny = i+1;
            // should have upper
            if(nx >=0 && ny >=0 && nx <n && ny <m && vis[ny][nx] == false && (grid[ny][nx] == 2 || grid[ny][nx] == 6 || grid[ny][nx] == 5)){
                ans = ans || solve(grid,ny,nx,vis);
            }
        }
         else if(grid[i][j] == 5){
            int nx = j-1;
            int ny = i;
             // should have right
            if(nx >=0 && ny >=0 && nx <n && ny <m && vis[ny][nx] == false && (grid[ny][nx] == 1 || grid[ny][nx] == 4 || grid[ny][nx] == 6)){
                ans = ans || solve(grid,ny,nx,vis);
            }
            nx = j;
            ny = i-1;
             // should have lower
           if(nx >=0 && ny >=0 && nx <n && ny <m && vis[ny][nx] == false && (grid[ny][nx] == 2 || grid[ny][nx] == 3 || grid[ny][nx] == 4)){
                ans = ans || solve(grid,ny,nx,vis);
            }
        }
         else if(grid[i][j] == 6){
            int nx = j+1;
            int ny = i;
             // should have left
           if(nx >=0 && ny >=0 && nx <n && ny <m && vis[ny][nx] == false && (grid[ny][nx] == 1 || grid[ny][nx] == 3 || grid[ny][nx] == 5)){
                ans = ans || solve(grid,ny,nx,vis);
            }
            nx = j;
            ny = i-1;
             // should have lower
          if(nx >=0 && ny >=0 && nx <n && ny <m && vis[ny][nx] == false && (grid[ny][nx] == 2 || grid[ny][nx] == 3 || grid[ny][nx] == 4)){
                ans = ans || solve(grid,ny,nx,vis);
            }
        }
        return ans;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        // dfs
        // if we can reech int grid at tpositon
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,false));
        return solve(grid,0,0,vis);
    }
};