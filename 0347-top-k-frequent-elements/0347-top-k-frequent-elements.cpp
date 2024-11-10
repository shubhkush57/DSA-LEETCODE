class Solution {
public:
    #define pp pair<int,int>
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto it: nums)mp[it]++;
        priority_queue<pp,vector<pp>,greater<pp>>pq;
        for(auto it: mp){
            pq.push({it.second,it.first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int>ans;
        while(!pq.empty()){
            pp t = pq.top();pq.pop();
            ans.push_back(t.second);
        }
        return ans;

    }
};