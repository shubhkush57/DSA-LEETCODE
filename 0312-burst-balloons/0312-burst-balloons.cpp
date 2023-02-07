class Solution {
public:
    int solve(vector<int>&nums,int i,int j,vector<vector<int>>&dp){
        int n = nums.size();
        if(i == j){
            if(i>0 && j<n-1){
                return (nums[i]*nums[i-1]*nums[i+1]);
            }
            else if(i>0 && j>=n-1){
                return (nums[i]*nums[i-1]);
            }
            else if(i<=0 && j<n-1){
                return nums[i]*nums[i+1];
            }
            return nums[i];
        }
        if(dp[i+1][j+1] != -1){
            return dp[i+1][j+1];
        }
        int ans = 0;
        for(int k = i;k<=j;k++){
            // if size is from i-j then the cost it will be having is
            int temp = 0;
            if(i>0 && j<n-1){
                temp = nums[k]*nums[i-1]*nums[j+1];
            }
            else if(i>0 && j>=n-1){
                temp = nums[k]*nums[i-1];
            }
            else if(i<=0 && j<n-1){
                temp = nums[k]*nums[j+1];
            }
            else{
                temp = nums[k];
            }
            ans = max(ans,temp+solve(nums,i,k-1,dp)+solve(nums,k+1,j,dp));
        }
        return dp[i+1][j+1] = ans;
        return ans;

    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = n-1;
        vector<vector<int>>dp(n+5,vector<int>(n+5,-1));
        int ans = solve(nums,i,j,dp);
        return ans;
    }
};