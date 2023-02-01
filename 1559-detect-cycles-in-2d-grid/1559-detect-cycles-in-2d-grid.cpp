class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        // bool contain cycle or not we can check
        int m = grid.size();
        int n = grid[0].size();
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};
        vector<vector<vector<int>>>vis(m,vector<vector<int>>(n,vector<int>(3,-1)));
        queue<pair<int,pair<int,int>>>q;
        for(int i = 0;i<m;i++){
            for(int j  = 0;j<n;j++){
        
                
                if(vis[i][j][0] == -1){
                    q.push({1,{i,j}});
                    
                    vis[i][j]= {1,i,j};
                    while(!q.empty()){
                        int t= q.size();
                        for(int k = 0;k<t;k++){
                            int l = q.front().first;
                            int x = q.front().second.first;
                            int y = q.front().second.second;
                            q.pop();
                            for(int p = 0;p<4;p++){
                                int nx = x+dx[p];
                                int ny = y+dy[p];
                                if(nx >=0 && ny >=0 && nx < m && ny < n && (grid[nx][ny] == grid[x][y])){
                                    if(vis[nx][ny][0] == -1){
                                        vis[nx][ny] = {l+1,x,y};
                                        q.push({l+1,{nx,ny}});
                                    }
                                    else{
                                        // already visted // and both are not parent of each other
                                        // now i wnat o tjust check of the
                                        // nx and ny should not be child of nx ,ny
                                            if((nx != vis[x][y][1] || ny != vis[x][y][2])){
                                                int s = vis[nx][ny][0];
                                                 if(s+l >= 4){
                                                    return true;
                                                }
                                            }
                                            
                                        
                                       
                                    }
                                }
                            }
                        }
                    }
                }
                
                
            }
        }
        // for(int i = 0;i<m;i++){
        //     for(int j = 0;j<n;j++){
        //         cout<<vis[i][j][1]<<' '<<vis[i][j][2]<<endl;
        //     }
        // }
        return false;
    }
};