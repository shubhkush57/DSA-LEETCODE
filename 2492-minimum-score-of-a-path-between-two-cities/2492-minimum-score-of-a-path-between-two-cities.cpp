class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        // Minimum Score of a Path Between Two Cities
        //BFS with allowance
        unordered_map<int,int>mp;
        unordered_map<int,vector<pair<int,int>>>mp_re;
        for(int i = 0;i<roads.size();i++){
            mp_re[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            mp_re[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        queue<pair<int,int>>q;
        q.push({1,INT_MAX});
        int ans = INT_MAX;
        // now getting the values in the right ordere
        while(!q.empty()){
            int t = q.size();
            for(int i =0;i<t;i++){
                int f = q.front().first;
                int v = q.front().second;
                q.pop();
                for(auto it: mp_re[f]){
                    if(!mp.count(it.first) || mp[it.first] > min(v,it.second)){
                        int mii = min(v,it.second);
                        mp[it.first] = mii;
                        q.push({it.first,mii});
                        if(it.first == n){
                            ans = min(ans,mii);
                        }
                    }
                }
            }
        }
        return ans;
    }
};