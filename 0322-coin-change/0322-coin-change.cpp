class Solution {
public:
    int solve(vector<int>&coins,int amount,int i,vector<vector<int>>&dp){
        int n = coins.size();
        if(amount == 0)return 0;
        if(i>=n) return 1e5;
        if(dp[amount][i] != -1)return dp[amount][i];
        int ans= 1e5;
        for(int j = 0;j<=(amount/coins[i]);j++){
            ans = min(ans,j+solve(coins,amount-(j*coins[i]),i+1,dp));
        }
        return dp[amount][i]= ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        // we can assume there are infinte no of money
        vector<vector<int>>dp(amount+1,vector<int>(coins.size(),-1)); 
        int ans = solve(coins,amount,0,dp);
        return ans >=1e5?-1: ans;
    }
};