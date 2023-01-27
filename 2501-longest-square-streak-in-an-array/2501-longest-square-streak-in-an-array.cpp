class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        map<long long,int>mp;
        for(int i =0;i<n;i++){
            mp[(long long)nums[i]] = i;
        }
        int ans = 0;
        for(auto it: mp){
            int count = 0;
            long long temp =(long long) it.first;
            while(mp.count(temp)){
                count++;
                temp = temp*temp;
            }
            ans = max(ans,count);
        }
        if(ans >= 2){
            return ans;
        }
        return -1;
    }
};