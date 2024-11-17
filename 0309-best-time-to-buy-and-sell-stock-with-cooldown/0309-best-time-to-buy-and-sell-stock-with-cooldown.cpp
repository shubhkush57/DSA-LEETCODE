class Solution {
public:
    // int solve(vector<int>& prices,int i,int have){
    //     int n = prices.size();
    //     if(i>=n)return 0;
    //     int ans = 0;
    //     if(have == 0){
    //         ans = max(ans,-prices[i]+solve(prices,i+1,1));
    //         ans = max(ans,solve(prices,i+1,0));
    //     }
    //     else{
    //         ans = max(ans,prices[i]+solve(prices,i+2,0));
    //         ans = max(ans,solve(prices,i+1,1));
    //     }
    //     return ans;
    // }
    int maxProfit(vector<int>& prices) {
        // cool down period of one day
        int n = prices.size();
        vector<vector<int>>dp(n+3,vector<int>(2,0));
        
        for(int i = n-1;i>=0;i--){
            for(int have = 1;have>=0;have--){
                int ans = 0;
                if(have == 0){
                    ans = max(ans,-prices[i]+dp[i+1][1]);
                    ans = max(ans,dp[i+1][0]);
                }
                else{
                    ans = max(ans,prices[i]+dp[i+2][0]);
                    ans = max(ans,dp[i+1][1]);
                }
                dp[i][have] = ans;
            }
        }
        return dp[0][0];
    }
};