class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        // set<int>st;
        unordered_map<int,int>mp;
        int i = n-1;
        for(auto it: nums){
            if(it<k)return -1;
            else if(it>k)mp[it]++;
        }
        return mp.size();
    }
};