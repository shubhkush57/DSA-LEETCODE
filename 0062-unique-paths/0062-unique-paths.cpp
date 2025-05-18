class Solution {
public:
    int solve(int s,int e,int m,int n,vector<vector<int>>&dp){
        if(s>=m || s<0 || e>=n|| e<0)return 0;
        if(s == m-1 && e == n-1)return 1;
        if(dp[s][e] != -1)return dp[s][e];
        return dp[s][e] = solve(s+1,e,m,n,dp)+solve(s,e+1,m,n,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int s =0,e = 0;
        return solve(0,0,m,n,dp);
        
    }
};