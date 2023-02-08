class Solution {
public:
    int solve(vector<int>&nums,int i,vector<int>&dp){
        int n  = nums.size(); // now take the value of the 
        if(i == n-1){
            return 0;
        }
        // value 
        // minimum number of ways
        // now take the valuef
        if(dp[i] != -1){
            return dp[i];
        }
        int ans = 10000;
        for(int j = i+1;j<=min(n-1,i+nums[i]);j++){
            // now jump to the index and 
            if(nums[j] != 0|| (nums[j] == 0 && j == n-1))
            ans = min(ans,1+solve(nums,j,dp));
        }
        return dp[i] = ans;
    }
    int jump(vector<int>& nums) {
        int start = 0;
        // mimiu numbers of jump
        // each index pe maximum no of jumps requrired store
        // max heap se to nahi hoga
        vector<int>dp(nums.size()+1,-1);
        return solve(nums,0,dp);
    }
};