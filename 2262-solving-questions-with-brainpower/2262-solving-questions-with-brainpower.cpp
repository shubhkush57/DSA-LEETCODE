class Solution {
public:
    #define int2 long long
    int2 solve(vector<vector<int>>&questions,int i,vector<int2>&dp){
        int n = questions.size();
        if(i>=n) return 0;
        if(dp[i] != -1)return dp[i];
        int2 ans = solve(questions,i+1,dp);
        ans = max(ans,questions[i][0]+solve(questions,min(n,i+questions[i][1]+1),dp));
        return dp[i] = ans;

    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<int2>dp(n+1,-1);
        return solve(questions,0,dp);
    }
};