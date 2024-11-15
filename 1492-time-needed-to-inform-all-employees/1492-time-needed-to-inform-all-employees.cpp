class Solution {
public:
    int solve(vector<vector<int>>&subOrdinates,vector<int>&informTime,int node){
        int ans = 0;
        for(auto it: subOrdinates[node]){
            ans = max(ans,solve(subOrdinates,informTime,it));
        }

        return ans+ informTime[node];
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        // we have to amke the adj list.
        int infoTime = 0;
        vector<vector<int>>subOrdinates(n,vector<int>());
        for(int i = 0;i<n;i++){
            if(manager[i] != -1)
            subOrdinates[manager[i]].push_back(i);
        }
        return solve(subOrdinates,informTime,headID);
    }
};