class Solution {
public:
    unordered_map<int,int>dp;
    int minDays(int n) {
        // simple dfs
        // value of n can be very large...
        if(n <= 1)return n;
        if(dp.count(n) == false){
            return dp[n] = 1+min(n%2 + minDays(n/2),n%3+minDays(n/3));
        }
        return dp[n];
    }
};