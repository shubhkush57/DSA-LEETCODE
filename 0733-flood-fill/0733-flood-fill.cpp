class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>>q;
        int m = image.size();
        int n= image[0].size();
        int oldcolor = image[sr][sc]; // this is color assing
        if(color == oldcolor){
            return image;
        }
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};
        q.push({sr,sc});
        while(!q.empty()){
            int xi = q.front().first;
            int yi = q.front().second;
            image[xi][yi] = color;
            q.pop();
            for(int i = 0;i<4;i++){
                int nxi = xi+ dx[i];
                int nyi = yi + dy[i];
                if(nxi >= 0 && nxi < m && nyi >=0 && nyi <n && image[nxi][nyi] == oldcolor){
                    q.push({nxi,nyi});
                }
            }
        }
        return image;
    }
};