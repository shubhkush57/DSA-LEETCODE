class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
       int n = nums.size();
       vector<int>dp;
        dp.push_back(nums[0]);
        for(int i = 0;i<n;i++){
            if(dp.back()<nums[i]){
                dp.push_back(nums[i]);
            }
            else{
                auto indx = lower_bound(dp.begin(),dp.end(),nums[i])-dp.begin();
                dp[indx] = nums[i];
            }
        }
       return dp.size();
    }
};