class Solution {
public:
    void dfs(int i,vector<int>&temp,string &t,vector<int>&vis,string &s,map<int,vector<int>>&mp){
        vis[i] = true;
        temp.push_back(i);
        t.push_back(s[i]);
        for(auto it: mp[i]){
            if(vis[it] == false){
                dfs(it,temp,t,vis,s,mp);
            }
        }
        return;
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        int m = pairs.size();
        map<int,vector<int>>mp;
        for(int i = 0;i<m;i++){
            mp[pairs[i][0]].push_back(pairs[i][1]);
            mp[pairs[i][1]].push_back(pairs[i][0]);
        }
        vector<int>vis(n,false);
        string ans = s;
        for(int i = 0;i<n;i++){
            if(vis[i] == false){
                vector<int>temp;
                string t = "";
                //dfs
                dfs(i,temp,t,vis,s,mp);
                sort(temp.begin(),temp.end());
                sort(t.begin(),t.end());
                for(int i = 0;i<temp.size();i++){
                    ans[temp[i]] = t[i];
                }
            }
        }
        return ans;
    }
};