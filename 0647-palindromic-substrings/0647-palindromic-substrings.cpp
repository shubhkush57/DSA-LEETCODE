class Solution {
public:
    bool solve(string &s,int i,int j,vector<vector<int>>&dp){
        int n = s.size();
        if(i>j || i>=n || j<0)return true;
        if(dp[i][j] !=-1)return dp[i][j];
        if(i+1<n)
        dp[i+1][j] = solve(s,i+1,j,dp);
        if(j-1>=0)
        dp[i][j-1] = solve(s,i,j-1,dp);

        return dp[i][j] = ((s[i] == s[j]) && solve(s,i+1,j-1,dp));
    }
    int countSubstrings(string s) {
        // let's do a queick dp 
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        solve(s,0,n-1,dp);
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                ans += dp[i][j];
            }
        }

        return ans;
    }
};