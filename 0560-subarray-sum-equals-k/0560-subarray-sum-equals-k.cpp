class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int ans = 0;
        int sum = 0;
        for(int i = 0;i<nums.size();i++){
            sum += nums[i];
            if(sum ==k){
                ans++;
            }
            int rem = sum-k;
            if(mp.count(rem)){
                ans += mp[rem];
            }
            mp[sum]++;
        }

        return ans;
    }
};