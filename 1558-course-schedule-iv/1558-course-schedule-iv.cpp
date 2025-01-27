class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        vector<bool>ans;
        vector<vector<bool>>isReach(numCourses,vector<bool>(numCourses,false));
        map<int,set<int>>mp;
        for(int i = 0;i<pre.size();i++){
            mp[pre[i][0]].insert(pre[i][1]);
        }
        // if there exits a path from u -> v
        for(int i = 0;i<numCourses;i++){
            queue<int>q;
            q.push(i);
            while(!q.empty()){
                int f = q.front();
                q.pop();
                isReach[i][f]= true;
                for(auto it: mp[f]){
                   if(isReach[i][it]== false){
                        q.push(it);
                   }
                }
            }
        }
        for(int i = 0;i<queries.size();i++){
            int u = queries[i][0];
            int v= queries[i][1];
            ans.push_back(isReach[u][v]);
        }
        return ans;
    }
};