class Solution {
public:
    #define pp pair<int,pair<int,int>>
    
    int minCost(vector<vector<int>>& grid) {
        queue<pp>q;
        int m = grid.size();
        int n = grid[0].size();
        // cout<<m<<' '<<n<<endl;
        q.push({0,{0,0}}); // cost, i,j
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};
        vector<vector<int>>vis(m,vector<int>(n,INT_MAX)); // vis
        int absans = INT_MAX;
        vis[0][0] = 0;
        while(!q.empty()){
            int t = q.size();
            for(int i = 0;i<t;i++){
                pp  temp = q.front();
                int x = temp.second.first;
                int y = temp.second.second;

                int cost = temp.first;
                if(x == m-1 && y == n-1){
                    absans = min(absans,cost);
                }
                q.pop();
                
                for(int j = 0;j<4;j++){
                    int nx =x +dx[j];
                    int ny =y +dy[j];
                    if(nx <m && ny < n && nx >=0 && ny >=0){
                        // vis[nx][ny] = true;
                        if(grid[x][y] == 1){
                            if(j == 3){
                                if(vis[nx][ny]> cost){
                                    vis[nx][ny] = cost;
                                    q.push({cost,{nx,ny}});

                                }
                            }
                            else if(j == 1){
                                // q.push({cost+1,{nx,ny}});
                                if(vis[nx][ny] > cost+1){
                                    vis[nx][ny] = cost+1;
                                    q.push({cost+1,{nx,ny}});

                                }
                            }
                            else if(j == 2){
                                // q.push({cost+1,{nx,ny}});
                                if(vis[nx][ny]> cost+1){
                                    vis[nx][ny] = cost+1;
                                    q.push({cost+1,{nx,ny}});

                                }
                            }
                            else if(j == 0){
                                // q.push({cost+1,{nx,ny}});
                                if(vis[nx][ny] > cost+1){
                                    vis[nx][ny] = cost+1;
                                    q.push({cost+1,{nx,ny}});

                                }
                            }
                        }
                        else if(grid[x][y] == 2){
                            if(j == 3){
                                // q.push({cost+1,{nx,ny}});
                                if(vis[nx][ny] > cost+1){
                                    vis[nx][ny]= cost+1;
                                    q.push({cost+1,{nx,ny}});

                                }
                            }
                            else if(j == 1){
                                // q.push({cost+1,{nx,ny}});
                                if(vis[nx][ny] > cost+1){
                                    vis[nx][ny]= cost+1;
                                    q.push({cost+1,{nx,ny}});

                                }
                            }
                            else if(j == 2){
                                // q.push({cost,{nx,ny}});
                                if(vis[nx][ny] > cost){
                                    vis[nx][ny] = cost;
                                    q.push({cost,{nx,ny}});

                                }
                            }
                            else if(j == 0){
                                // q.push({cost+1,{nx,ny}});
                                if(vis[nx][ny] > cost+1){
                                    vis[nx][ny] = cost+1;
                                    q.push({cost+1,{nx,ny}});

                                }
                            }
                        }
                        else if(grid[x][y] == 3){
                            if(j == 3){
                                // q.push({cost+1,{nx,ny}});
                                if(vis[nx][ny]> cost+1){
                                    vis[nx][ny]= cost+1;
                                    q.push({cost+1,{nx,ny}});

                                }
                            }
                            else if(j == 1){
                                // q.push({cost,{nx,ny}});
                                if(vis[nx][ny] >cost){
                                    vis[nx][ny] = cost;
                                    q.push({cost,{nx,ny}});

                                }
                            }
                            else if(j == 2){
                                // q.push({cost+1,{nx,ny}});
                                if(vis[nx][ny] > cost+1){
                                    vis[nx][ny] = cost+1;
                                    q.push({cost+1,{nx,ny}});

                                }
                            }
                            else if(j == 0){
                                // q.push({cost+1,{nx,ny}});
                                if(vis[nx][ny]> cost+1){
                                    vis[nx][ny] = cost+1;
                                    q.push({cost+1,{nx,ny}});

                                }
                            }
                        }
                        else if(grid[x][y] == 4){
                            if(j == 3){
                                // q.push({cost+1,{nx,ny}});
                                if(vis[nx][ny] > cost+1){
                                    vis[nx][ny] = cost+1;
                                    q.push({cost+1,{nx,ny}});

                                }
                            }
                            else if(j == 1){
                                // q.push({cost+1,{nx,ny}});
                                if(vis[nx][ny]> cost+1){
                                    vis[nx][ny] = cost+1;
                                    q.push({cost+1,{nx,ny}});

                                }
                            }
                            else if(j == 2){
                                // q.push({cost+1,{nx,ny}});
                                if(vis[nx][ny]> cost+1){
                                    vis[nx][ny] = cost+1;
                                    q.push({cost+1,{nx,ny}});

                                }
                            }
                            else if(j == 0){
                                // q.push({cost,{nx,ny}});
                                if(vis[nx][ny] > cost){
                                    vis[nx][ny] = cost ;
                                    q.push({cost,{nx,ny}});

                                }
                            }
                        }

                    }

                }

            }
        }
        return absans;
    }
};