class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // coin change with amount as dp..
        vector<int>dp(amount+1,amount+1);
        int n = coins.size();
        dp[0] = 0;
        for(auto coin : coins){
            for(int j= 1;j<=amount;j++){
                if(j>=coin){
                    dp[j] = min(dp[j],dp[j-coin]+1);
                }
            }
        }
        return dp[amount] == (amount+1)?-1: dp[amount];
    }
};