class Solution {
public:
    void solve(vector<vector<int>>&grid,vector<vector<int>>&vis,int si,int sj,int ei,int ej,int total,int &ans){
        int m  = grid.size();
        int n = grid[0].size();
        if(si>=m || si<0 || sj >=n || sj<0 || vis[si][sj] ==  1 || grid[si][sj] ==  -1){
            return;
        }
        if(si == ei && sj == ej){
            if(total == 1){
                ans++;
            }
            return;
        }
        vis[si][sj] = 1;
        solve(grid,vis,si+1,sj,ei,ej,total-1,ans);
        solve(grid,vis,si-1,sj,ei,ej,total-1,ans);
        solve(grid,vis,si,sj+1,ei,ej,total-1,ans);
        solve(grid,vis,si,sj-1,ei,ej,total-1,ans);
        vis[si][sj] = 0;
        return;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // for a path we have to visit all the non obstacle path 
        // if we can visit all the non -obstacle paths exactly once then that will be ans+1
        int si;
        int sj;
        int ei;
        int ej;
        int total = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] != -1){
                    total++;
                }
                if(grid[i][j] == 1){
                    si = i;
                    sj = j;
                }
                if(grid[i][j] == 2){
                    ei = i;
                    ej = j;
                }
            }
        }
        // total path we need to if 
        int ans = 0;
        vector<vector<int>>vis(m,vector<int>(n,0));
        solve(grid,vis,si,sj,ei,ej,total,ans);
        return ans;
    }
};