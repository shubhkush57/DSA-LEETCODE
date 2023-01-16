class Solution {
public:
    bool isPossible(vector<vector<int>>&v,int mid,int thres){
        int n = v.size();
        int m = v[0].size();
        for(int i = 0;i<=n-mid;i++){
            for(int j = 0;j<=m-mid;j++){
                int temp = v[i+mid-1][j+mid-1];
                if(i-1>=0){
                    temp -= v[i-1][j+mid-1];
                }
                if(j-1>=0){
                    temp -= v[i+mid-1][j-1];
                }
                if((i-1)>=0 && (j-1)>=0){
                    temp += v[i-1][j-1];
                }
                if(temp<= thres){
                    return true;
                }
            }
        }
        return false;
    }
    int maxSideLength(vector<vector<int>>& mat, int thres) {
        int n = mat.size();
        int m = mat[0].size();
        int start= 1;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                // v[i][j] = mat[i][j]+sum[i-1][j]+sum[i][j-1] -mat[i-1][j-1];
                int sum = mat[i][j];
                if(i-1>=0){
                    sum += mat[i-1][j];
                }
                if(j-1>=0){
                    sum += mat[i][j-1];
                }
                if((i-1) >= 0 && (j-1)>=0){
                    sum -= mat[i-1][j-1];
                }
                mat[i][j] = sum;
            }
            
        }
        int end = min(n,m);
        int ans = 0;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(isPossible(mat,mid,thres)){
                ans = mid;
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return ans;
    }
};