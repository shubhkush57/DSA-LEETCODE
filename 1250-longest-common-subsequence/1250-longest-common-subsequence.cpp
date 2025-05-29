class Solution {
public:
    int solve(string &text1,int i,string &text2,int j,vector<vector<int>>&dp){
        int n1 = text1.size(),n2 = text2.size();
        if(i>=n1 || j>=n2)return 0;
        if(dp[i][j] != -1)return dp[i][j];
        int ans = 0;
        if(text1[i] == text2[j]){
            ans = max(ans,1+solve(text1,i+1,text2,j+1,dp));
        }
        ans = max({ans,solve(text1,i+1,text2,j,dp),solve(text1,i,text2,j+1,dp)});
        return dp[i][j] = ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int i = 0,j = 0;
        int n1 = text1.size(),n2 = text2.size();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return solve(text1,i,text2,j,dp);
    }
};