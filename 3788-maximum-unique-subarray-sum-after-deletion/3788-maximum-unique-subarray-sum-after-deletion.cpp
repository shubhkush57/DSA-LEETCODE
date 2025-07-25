class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>vis;
        int ans = 0;
        int posAns = *max_element(nums.begin(),nums.end());
        for(auto it: nums){
            if(it>0 && !vis.count(it)){
                ans += it;
                vis[it]++;
            }
        }
        return vis.empty()?posAns: ans;
    }
};