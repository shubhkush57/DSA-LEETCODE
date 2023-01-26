class Solution {
public:
    int solve1(vector<int>&nums,int i,vector<int>&dp1){
        int n = nums.size();
        if( i>=n-1){
            return 0;
        }
        if(dp1[i] != -1){
            return dp1[i];
        }
        int ans = 0;
        int temp2 = solve1(nums,i+1,dp1);
        int temp1 = nums[i] + solve1(nums,i+2,dp1);
        ans = max(temp1,temp2);
        return dp1[i] = ans;
    }
    int solve2(vector<int>&nums,int i,vector<int>&dp2){
        int n = nums.size();
        if(i >=n){
            return 0;
        }
        if(dp2[i] != -1){
            return dp2[i];
        }
        int ans = 0;
        int temp2 = solve2(nums,i+1,dp2);
        int temp1 = nums[i] + solve2(nums,i+2,dp2);
        ans = max(temp1,temp2);
        return dp2[i] = ans;
        
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        vector<int>times(n,0);
        int i = 0;
        int ans = 0;
        vector<int>dp1(n+1,-1);
        ans = solve1(nums,i,dp1);
        i = 1;
        vector<int>dp2(n+1,-1);
        ans = max(ans,solve2(nums,i,dp2));
        return ans;
    }
};