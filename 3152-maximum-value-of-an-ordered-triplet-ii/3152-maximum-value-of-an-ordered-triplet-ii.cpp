class Solution {
public:
    #define int2 long long
    long long maximumTripletValue(vector<int>& nums) {
        int2 ans = 0;
        int n = nums.size();
        int2 maxDiff = 0,maxValue = nums[0];
        for(int i = 1;i<n;i++){
            ans = max(ans,maxDiff*nums[i]); 
            maxDiff = max(maxDiff,maxValue-nums[i]);
            maxValue = max(maxValue,(int2)nums[i]);
        }
        return ans;
    }
};