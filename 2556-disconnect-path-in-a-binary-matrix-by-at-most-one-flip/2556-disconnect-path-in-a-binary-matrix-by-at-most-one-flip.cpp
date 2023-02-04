class Solution {
public:
    // path possible or not
    bool dfs(vector<vector<int>>&grid,int i,int j){
        int m = grid.size();
        int n = grid[0].size();
        if(i == m - 1 && j == n-1){
            return true;
        }
        if(i >= m || i <0 || j>=n || j<0 || grid[i][j] == 0){
            return false;
        }
        grid[i][j] = 0;
        return dfs(grid,i+1,j) || dfs(grid,i,j+1);
    }
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        bool possible = dfs(grid,0,0);
        if(possible == false){
            return true;
        }
        grid[0][0] = 1;
        return !dfs(grid,0,0);
        
    }
};