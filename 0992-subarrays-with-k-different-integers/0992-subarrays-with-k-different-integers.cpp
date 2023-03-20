class Solution {
public:
    int subarryWithAtleastKDistinct(vector<int>&nums,int k){
        int n = nums.size();
        unordered_map<int,int>mp;
        int ans = 0;
        int i = 0,j= 0;
        while(j<n ){
            if(mp.size() <k){
                mp[nums[j]]++;
                while(mp.size() == k){
                    ans += n-j;
                    mp[nums[i]]--;
                    if(mp[nums[i]] == 0){
                        mp.erase(nums[i]);
                    }
                    i++;
                }
            }
            j++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarryWithAtleastKDistinct(nums,k)-subarryWithAtleastKDistinct(nums,k+1);
    }
};