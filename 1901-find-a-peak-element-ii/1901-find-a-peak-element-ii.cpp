class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        vector<int>ans;
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                int mid = j;
                bool flag = true;
                for(int k = 0;k<4;k++){
                    int nx = i+dx[k];
                    int ny = mid+dy[k];
                    if(nx >=0 && ny >=0 &&nx<n && ny < m&& mat[nx][ny]>mat[i][mid]){
                        flag = false;
                    }
                }
                if(flag == true){
                    return {i,mid};
                }
            }
        }
        return ans;
    }
};