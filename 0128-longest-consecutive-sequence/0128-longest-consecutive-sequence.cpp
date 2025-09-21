class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto it: nums)mp[it]++;
        int ans = 0;
        for(auto it: mp){
            int ele = it.first;
            if(!mp.count(ele+1)){
                int len = 1;
                while(mp.count(ele-len)){
                    len++;
                }
                ans = max(ans,len);
            }
        }

        return ans;
    }
};