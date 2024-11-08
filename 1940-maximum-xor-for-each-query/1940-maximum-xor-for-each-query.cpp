class Solution {

public:

    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int xorArr = 0,mask = (1<<maximumBit)-1,n = nums.size();
        vector<int>ans(n);
        for(int i = 0;i<n;i++){
            xorArr = xorArr xor nums[i];
            ans[n-1-i]  = mask & (~xorArr);
        }
        return ans;

    }

};