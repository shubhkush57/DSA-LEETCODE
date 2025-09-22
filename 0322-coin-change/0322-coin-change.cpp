class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int>dp(amount+1,amount+1);
        dp[0] = 0;
        for(int a = 1;a<=amount;a++){
            for(int coin: coins){
                // coin will not be greater than amount
                if(a>=coin ){
                    dp[a] = min(1+dp[a-coin],dp[a]);
                }
            }
        }
        return dp[amount] != amount+1? dp[amount]: -1;
    }
};