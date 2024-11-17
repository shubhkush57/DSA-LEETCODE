class Solution {
public:
    void solve(vector<int>&candidates,vector<vector<int>>&ans,vector<int>&re,int target,int start){
        if(target == 0){
            ans.push_back(re);
            return;
        }
        for(int indx = start;indx<candidates.size();indx++){
            if(start != indx && candidates[indx] == candidates[indx-1])continue;
            if(target-candidates[indx]>=0){
                re.push_back(candidates[indx]);
                solve(candidates,ans,re,target-candidates[indx],indx+1);
                re.pop_back();
            }
            
        }

        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // when sum 
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>re;
        solve(candidates,ans,re,target,0);
        return ans;
        
    }
};