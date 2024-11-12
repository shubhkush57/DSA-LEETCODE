class Solution {
public:
    int solve(vector<int>&nums,int prev,int i,vector<vector<int>>&dp){
        int n = nums.size();
        if(i>=n)return 0;
        if(dp[prev+1][i] != -1)return dp[prev+1][i];
        int ans = solve(nums,prev,i+1,dp);
        if(prev == -1 || nums[prev]<nums[i]){
            ans = max(ans,1+ solve(nums,i,i+1,dp));
        }
        return dp[prev+1][i] = ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
        int prev = -1;
        return solve(nums,prev,0,dp);
    }
};