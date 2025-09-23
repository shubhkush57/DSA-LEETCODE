class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    #define pp pair<int,int>
    vector<vector<bool>> fillAtlanticWater(vector<vector<int>>& heights){
        int m = heights.size(),n = heights[0].size();
        queue<pair<int,int>>q;
        vector<vector<bool>>filled(m,vector<bool>(n,false));
        for(int i = 0;i<n;i++){
            q.push({m-1,i});
            filled[m-1][i] = true;
        }
        for(int i = 0;i<m;i++){
            q.push({i,n-1});
            filled[i][n-1] = true;
        }
        while(!q.empty()){
            int t= q.size();
            while(t--){
                pp temp = q.front();q.pop();
                int x = temp.first,y = temp.second;
                for(int k = 0;k<4;k++){
                    int nx = x+dx[k],ny = y+dy[k];
                    if(nx>=0 && nx<m && ny>=0 && ny<n && heights[nx][ny] >= heights[x][y] && filled[nx][ny] == false){
                        q.push({nx,ny});
                        filled[nx][ny] = true;
                    }
                }
            }
        }
        return filled;
    }
    vector<vector<bool>> fillPacificWater(vector<vector<int>>& heights){
        int m = heights.size(),n = heights[0].size();
        queue<pair<int,int>>q;
        vector<vector<bool>>filled(m,vector<bool>(n,false));
        for(int i = 0;i<n;i++){
            q.push({0,i});
            filled[0][i] = true;
        }
        for(int i = 0;i<m;i++){
            q.push({i,0});
            filled[i][0] = true;
        }
        while(!q.empty()){
            int t= q.size();
            while(t--){
                pp temp = q.front();q.pop();
                int x = temp.first,y = temp.second;
                for(int k = 0;k<4;k++){
                    int nx = x+dx[k],ny = y+dy[k];
                    if(nx>=0 && nx<m && ny>=0 && ny<n && heights[nx][ny] >= heights[x][y] && filled[nx][ny] == false){
                        q.push({nx,ny});
                        filled[nx][ny] = true;
                    }
                }
            }
        }
        return filled;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(),n = heights[0].size();
        vector<vector<int>>ans;
        vector<vector<bool>> a = fillAtlanticWater(heights);
        vector<vector<bool>> p = fillPacificWater(heights);
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(a[i][j]  && p[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};