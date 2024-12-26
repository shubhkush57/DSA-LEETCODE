class Solution {
public:
    int solve(vector<int>&nums,int i,int target){
        int n = nums.size();
        if(i>=n){
            return target == 0;
        }
        return solve(nums,i+1,target-nums[i])+solve(nums,i+1,target+nums[i]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        // we have to build the target sum as the above we will be having things like
        // 
        return solve(nums,0,target);
    }
};