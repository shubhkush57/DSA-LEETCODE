class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        int currentSum = 0;        
        for(int i = 0;i<n;i++){
            if(currentSum+nums[i]>nums[i]){
                currentSum += nums[i];
            }
            else{
                currentSum =nums[i];
            }
            ans = max(ans,currentSum);
        }

        return ans;
    }
};