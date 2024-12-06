class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int siz = banned.size();
        unordered_map<int,int>mp;
        for(auto it: banned)mp[it]++;
        int ans = 0;
        for(int i = 1;i<=n;i++){
            if(mp.count(i) == false && (maxSum-i)>=0){
                maxSum -= i;
                ans++;
            }
        }
        return ans;
    }
};