class Solution {
public:
    unordered_map<char,int> solve(map<int,vector<int>>&mp,string & labels,vector<int>&ans,int root,vector<bool>&vis){
        if(vis[root]){
            unordered_map<char,int>mp1;
            ans[root]++;
            mp1[labels[root]]++;
            return mp1;
        }
        vis[root] = true;
        unordered_map<char,int>mpr;
        mpr[labels[root]]++;
        for(auto it: mp[root]){
            unordered_map<char,int>mpn;
            if(vis[it] == false){
                mpn = solve(mp,labels,ans,it,vis);
                vis[it] = true;
            }
            for(auto it1: mpn){
                mpr[it1.first] += it1.second;
            }
        }
        ans[root] += mpr[labels[root]];
        return mpr;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {   
        map<int,vector<int>>mp;
        int n1= edges.size();
        int m = labels.size();
        for(int i = 0;i<n1;i++){
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool>vis(n,false);
        vector<int>ans(m,0);
        int root = 0;
        solve(mp,labels,ans,root,vis);
        return ans;
        
    }
};