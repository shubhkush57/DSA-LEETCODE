class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    #define pp pair<pair<int,int>, pair<int,int>>
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<int>>vis(n,vector<int>(m,INT_MAX));
        int ans = INT_MAX;
        // queue<pp>q;
        priority_queue<pp,vector<pp>,greater<pp>>q;
        q.push({{0,0},{0,0}});
        vis[0][0] = 0;
        while(!q.empty()){
            int t = q.size();
            while(t--){
                pp f = q.top();q.pop();
                int x = f.second.first;
                int y = f.second.second;
                int moves = f.first.first;
                int alt = f.first.second;
                if(x == n-1 && y ==  m-1){
                    // ans = min(ans,moves);
                    return moves;
                }
                for(int i = 0;i<4;i++){
                    int nx = x+dx[i],ny = y+dy[i];
                    if(nx>=0 && ny>=0 && nx<n && ny<m){
                        int cal = moveTime[nx][ny] - moves;
                        if(cal<0){
                            if(vis[nx][ny]>moves+alt+1){
                                vis[nx][ny] = moves+alt+1;
                                q.push({{vis[nx][ny],!alt},{nx,ny}});
                            }
                        }
                        else{
                           
                            if(vis[nx][ny]>moves+cal){
                                vis[nx][ny] = moves+cal+alt+1;
                                q.push({{vis[nx][ny],!alt},{nx,ny}});
                            }
                        }
                    }
                }
            }
            // cout<<alt<<endl;
        }
       
        return ans;
        
    }
};