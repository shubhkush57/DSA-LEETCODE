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
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        if(m == 1 && n== 1){
            return 0;
        }
        int start = 0;
        int end = INT_MAX;
        int ans = end;
        while(start<=end){
            // now taking the values of the 
            int mid = start+(end-start)/2;
            if(isPossible(heights,mid)){
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