class Solution {
public:
    int solve(map<int,vector<int>>&mp,string &s,vector<bool>&vis,int &reans,int root){
        int l1 = 0;
        int l2 = 0;
        vis[root] = true;
        int tempmax = 0;
        for(auto it: mp[root]){
            if(vis[it] == false){
                int temp = solve(mp,s,vis,reans,it);
                if(s[it] != s[root]){
                    tempmax = max(tempmax,temp);
                    // l1 = max(l1,temp);
                    if(temp> l2){
                        l2 = temp;
                    }
                    if(l2>l1){
                        swap(l1,l2);
                    }
                    
                }
                
            }
        }
        reans = max(reans,l1+l2+1);
        reans = max(reans,tempmax+1);
        return tempmax+1;
    }
    int longestPath(vector<int>& parent, string s) {
        map<int,vector<int>>mp;
        int n = s.size();
        if(n == 1){
            return 1;
        }
        int reans = 0;
        for(int i = 1;i<n;i++){
            mp[i].push_back(parent[i]);
            mp[parent[i]].push_back(i);
        }
        vector<bool>vis(n,false);
        int root= 0;
        solve(mp,s,vis,reans,root);
        return reans;
    }
};