class Solution {
public:
    bool isPossible(vector<vector<int>>&grid,int time){
        int n = grid.size();
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};
        queue<pair<int,int>>q;
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        q.push({0,0});
        vis[0][0] = true;
        if(grid[0][0] > time){
            return false;
        }
        while(!q.empty()){
            int t = q.size();
            for(int i = 0;i<t;i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int j = 0;j<4;j++){
                    int nx = x+dx[j];
                    int ny = y+dy[j];
                    if(nx >=0 && ny <n && nx<n && ny>=0 && vis[nx][ny] == false && grid[x][y] <= time && grid[nx][ny]<=time){ 
                        q.push({nx,ny});
                        vis[nx][ny] = true;
                        if(nx == n-1 && ny == n-1){
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        // you have to find the path with form 00 to n-1 n-1  the minimum value
        int ans = INT_MAX;
        int start = 0;
        int end = 2505;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(isPossible(grid,mid)){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        if(ans == INT_MAX){
            return 0;
        }
        return ans;
    }
};