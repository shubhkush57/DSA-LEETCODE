class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    bool isPossible(vector<vector<int>>&heights,int mid){
        int m = heights.size();
        int n = heights[0].size();
        //BFS
        queue<pair<int,int>>q;
        vector<vector<int>>vis(m,vector<int>(n,0));
        q.push({0,0});
        vis[0][0] = 1;
        while(!q.empty()){
            pair<int,int>f = q.front();
            q.pop();
            for(int i = 0;i<4;i++){
                int nx = f.first+dx[i];
                int ny = f.second+dy[i];
                if(nx>=0 && ny >=0 && nx<m && ny <n && vis[nx][ny] == 0){
                    if(abs(heights[f.first][f.second]-heights[nx][ny]) <=mid){
                        q.push({nx,ny});
                        vis[nx][ny] = 1;
                        if(nx == m-1 && ny == n-1){
                            return true;
                        }
                    }
                    
                }
            }
        }
        return false;
    }
    bool solve(vector<vector<int>>&heights,int mid,int x,int y,vector<vector<bool>>&vis){       
        int m = heights.size();
        int n = heights[0].size();
        if(x == m-1 && y == n-1){
            return true;
        }
        bool ans = false;
        for(int i = 0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0 && nx<m && ny >=0 && ny<n && vis[nx][ny] == false){
                int diff = abs(heights[nx][ny]-heights[x][y]);
                if(diff<=mid){
                     vis[nx][ny] = true;

                    ans = ans || solve(heights,mid,nx,ny,vis);
                }
            }
        }
        return ans;
        
    }
    bool isPossible2(vector<vector<int>>&heights,int mid){
        int m = heights.size();
        int n = heights[0].size();
        int x = 0;
        int y = 0;
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        vis[x][y] = true;
        return solve(heights,mid,x,y,vis);
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        if(m == 1 && n== 1){
            return 0;
        }
        int start = 0;
        int end = 1e6+1;
        int ans = end;
        while(start<=end){
            // now taking the values of the 
            int mid = start+(end-start)/2;
            if(isPossible2(heights,mid)){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ans;
    }
};