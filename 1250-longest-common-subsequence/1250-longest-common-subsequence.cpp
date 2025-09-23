class Solution {
public:
    int solve(string &text1,int i,string &text2,int j,vector<vector<int>>&dp){
        int n =text1.size(), m = text2.size();
        if(i>=n || j>=m)return 0;
        if(dp[i][j] != -1)return dp[i][j];
        int ans = 0;
        if(text1[i] == text2[j]){
            ans = 1+ solve(text1,i+1,text2,j+1,dp);
        }
        ans = max({ans,solve(text1,i,text2,j+1,dp),solve(text1,i+1,text2,j,dp)});
        return dp[i][j] = ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n =text1.size(), m = text2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(text1,0,text2,0,dp);
    }
};