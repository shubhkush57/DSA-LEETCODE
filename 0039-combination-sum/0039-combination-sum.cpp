class Solution {
public:
    void solve(vector<int>&candidates,vector<vector<int>>&ans,vector<int>&v,int i,int target){
        int n = candidates.size();
        if(target == 0){
            ans.push_back(v);return;
        }
        if(i>=n)return;
        solve(candidates,ans,v,i+1,target);
        if(target-candidates[i]>=0){
            v.push_back(candidates[i]);
            solve(candidates,ans,v,i,target-candidates[i]);
            v.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>>ans;
        vector<int>v;
        solve(candidates,ans,v,0,target);
        return ans;
    }
};