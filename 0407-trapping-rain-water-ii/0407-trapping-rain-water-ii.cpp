class Solution {
public:
    #define vi vector<int>
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    int trapRainWater(vector<vector<int>>& heightMap) {
        // how to tackle drainage.
        int m = heightMap.size();
        int n = heightMap[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        priority_queue<vi,vector<vi>,greater<vi>>pq;
        // push the boundry elemnts
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(i == 0 || i == m-1 || j == 0 || j == n-1){
                    if(!vis[i][j]){
                        pq.push({heightMap[i][j],i,j});
                        vis[i][j] = true;
                    }
                }
            }
        }
        int ans = 0;
        while(!pq.empty()){
            vi f = pq.top();pq.pop();
            int x = f[1],y = f[2];
            int w = f[0];
            for(int k = 0;k<4;k++){
                int nx = x+dx[k];
                int ny = y+dy[k];
                if(nx>=0 && nx<m && ny>=0 && ny<n && vis[nx][ny] == false){
                    if(heightMap[nx][ny] <=w){
                        ans += w-heightMap[nx][ny];
                        pq.push({w,nx,ny});
                    }
                    else{
                        pq.push({heightMap[nx][ny],nx,ny});
                    }
                    vis[nx][ny] = true;
                }
            }
        }
        return ans;
    }
};