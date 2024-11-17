class Solution {
public:
    int solve(vector<int>& coins,int amount,int i,vector<vector<int>>&dp){
        int n = coins.size();
        if(i>=n){
            return amount == 0;
        }
        if(dp[i][amount] != -1)return dp[i][amount];
        int ans = solve(coins,amount,i+1,dp);
        if(amount-coins[i]>=0)
        ans += solve(coins,amount-coins[i],i,dp);
        return dp[i][amount] = ans;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return solve(coins,amount,0,dp);
    }
};