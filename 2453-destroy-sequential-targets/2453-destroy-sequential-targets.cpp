class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        unordered_map<int,pair<int,int>>mp;
        for(int i =n-1;i>=0;i--){
            int t = nums[i]%space;
            mp[t].first = mp[t].first+1;
            mp[t].second = nums[i];
        }
        int ans = INT_MAX;
        int count  = 0;
        for(auto it: mp){
            // cout<<it.first<<' '<<it.second.first<<' '<<it.second.second<<endl;
            if(it.second.first > count){
                count = it.second.first;
                // if(it.second.second < ans){
                //     ans = it.second.second;
                // }
                ans = it.second.second;
            }
            else if(it.second.first == count){
                if(it.second.second<ans){
                    ans = it.second.second;
                }
            }
        }
        return ans;
    }
};