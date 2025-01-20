class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();
        vector<int>row((m*n+1),0),col((m*n)+1);
        for(int i= 0;i<m;i++){
            for(int j = 0;j<n;j++){
                row[mat[i][j]] = i;
                col[mat[i][j]] = j;
            }
        }
        vector<int>countRow(m,0),countCol(n,0);
        for(int i = 0;i<arr.size();i++){
            int r = row[arr[i]],c = col[arr[i]];
            countRow[r]++;
            countCol[c]++;
            if(countRow[r] == n || countCol[c] == m)return i;
        }
        return -1;
    }
};