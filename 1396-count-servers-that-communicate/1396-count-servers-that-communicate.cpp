class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int>row(m,0),col(n,0);
        for(int i = 0;i<m;i++){
            int count = 0;
            for(int j = 0;j<n;j++){
                // we need to clear the things...
                count += grid[i][j];
            }
            row[i] = count;
        }
        for(int j = 0;j<n;j++){
            int count = 0;
            for(int i = 0;i<m;i++){
                count += grid[i][j];
            }
            col[j] = count;
        }
        int ans = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 1 && (row[i] >1 || col[j] >1 ))ans++;
            }
        }
        return ans;
    }
};