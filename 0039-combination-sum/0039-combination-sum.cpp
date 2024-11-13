class Solution {
public:
    void solve(vector<int>& candidates,set<vector<int>>&ans,vector<int>&v,int target,int i){
        int n = candidates.size();
        if(target == 0){
            ans.insert(v);
            return;
        }
        if(i>=n)return;
        solve(candidates,ans,v,target,i+1);
        if(target-candidates[i] >=0){
            v.push_back(candidates[i]);
            solve(candidates,ans,v,target-candidates[i],i+1);
            solve(candidates,ans,v,target-candidates[i],i);
            v.pop_back();
        }
        return;
        // I am not where I suppose to be.
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        set<vector<int>>ans;
        vector<int>v;
        solve(candidates,ans,v,target,0);
        vector<vector<int>>desAns;
        for(auto it: ans)desAns.push_back(it);
        return desAns;
    }
};