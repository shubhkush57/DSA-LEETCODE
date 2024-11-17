class Solution {
public:
    bool solve(vector<int>&nums,int target,int i,vector<vector<int>>&dp){
        int n = nums.size();
        if(i>=n)return target == 0;
        if(dp[i][target] != -1)return dp[i][target];
        bool ans= solve(nums,target,i+1,dp);
        if(target-nums[i]>=0){
            ans = ans or solve(nums,target-nums[i],i+1,dp);
        }
        return dp[i][target]=ans;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2)return false;
        sum = sum/2;
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return solve(nums,sum,0,dp);
    }
};