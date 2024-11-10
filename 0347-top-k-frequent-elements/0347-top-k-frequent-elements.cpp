class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // if k is the no of element.. elements...
        int n = nums.size();
        unordered_map<int,int>mp;
        for(auto it: nums){
            mp[it]++;
        }
        // freq is 3 then we will see if the numbers are like that.
        vector<vector<int>>bucket(n+1,vector<int>());
        vector<int>ans;
        for(auto it: mp){
            bucket[it.second].push_back(it.first);
        }
        // top element having the highest freq are int he right..
        for(int i = n;i>=0;i--){
            for(int j = 0;j<bucket[i].size() && k>0 ; j++){
                ans.push_back(bucket[i][j]);
                k--;
            }
        }
        return ans;
    }
};