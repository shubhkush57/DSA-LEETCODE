class Solution {
public:
    int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for(int i = 0;i<m;i++){
            for(int j= 0;j<n;j++){
                if(grid[i][j] >0){
                    
                    vector<vector<bool>>vis(m,vector<bool>(n,false));
                    int count = 0;
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    vis[i][j] = true;
                    while(!q.empty()){
                        int t= q.size();
                        for(int k = 0;k<t;k++){
                            int fx = q.front().first;
                            int fy = q.front().second;
                            q.pop();
                            count += grid[fx][fy];
                            for(int s = 0;s<4;s++){
                                int nx = fx+dx[s];
                                int ny = fy+dy[s];
                                if(nx >=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]>0 && vis[nx][ny] == false){
                                    q.push({nx,ny});
                                    vis[nx][ny] = true;
                                }
                            }
                        }
                    }
                    ans = max(ans,count);
                }
            }
        }
        return ans;
    }
};