class Solution {
public:
    int dx[4] ={-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    #define int2 long long
    #define vi vector<int2>

    int minimumTime(vector<vector<int>>& grid) {
        int2 m = grid.size();
        int2 n = grid[0].size();
        if(grid[0][1]>1 && grid[1][0]>1)return -1;
        priority_queue<vi,vector<vi>,greater<vi>>pq;
        vector<vi>vis(m,vi(n,LLONG_MAX));
        pq.push({0,0,0});
        vis[0][0] = 0;
        while(!pq.empty()){
            vi f = pq.top();pq.pop();
            int2 x = f[1];
            int2 y = f[2];
            int2 time = f[0];
            if(x == m-1 && y == n-1){
                return time;
            }
            for(int i = 0;i<4;i++){
                int2 nx = x+dx[i];
                int2 ny = y+dy[i];
                if(nx>=0 && ny>=0 && nx< m && ny<n){
                    if(grid[nx][ny]<=time+1){
                        if(vis[nx][ny]>time+1){
                            vis[nx][ny] = time+1;
                            pq.push({vis[nx][ny],nx,ny});
                        }
                    }
                    else{
                        int2 diff = grid[nx][ny]-(time+1);
                        int2 re = ceil(diff/2.0);
                        re = re*2;
                        int2 timer = time+1+re;
                        vis[nx][ny] = timer;
                        pq.push({vis[nx][ny],nx,ny});
                    }
                }
                
            }
        }
        return -1;
    }
};