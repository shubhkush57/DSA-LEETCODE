class Solution {
public:
    #define pp pair<int,int>
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    void makeWater(vector<vector<char>>&grid,int i,int j){
        int n = grid.size();
        int m = grid[0].size();
        queue<pp>q;
        q.push({i,j});
        grid[i][j] = '0';
        while(!q.empty()){
            int t= q.size();
            while(t--){
                pp f = q.front();q.pop();
                int x = f.first;
                int y = f.second;
                for(int k = 0;k<4;k++){
                    int nx = x+dx[k];
                    int ny = y+dy[k];
                    if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny] != '0'){
                        grid[nx][ny] = '0';
                        q.push({nx,ny});
                    }
                }
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        // we have to get the number of island....
        int n = grid.size();
        int m = grid[0].size();
        int noOfIsland = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == '1'){
                    makeWater(grid,i,j);
                    noOfIsland++;
                }
            }
        }
        return noOfIsland;
    }
};