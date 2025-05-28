class Solution {
public:
    void solve(vector<int>&nums,int start,vector<vector<int>>&ans){
       int n = nums.size();
       if(start>=n){
            ans.push_back(nums);
       }
       for(int i = start;i<n;i++){
         swap(nums[i],nums[start]);
         solve(nums,start+1,ans);
         swap(nums[i],nums[start]);
       }
       return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        // use swapping
        vector<vector<int>>ans;
        solve(nums,0,ans);
        return ans;
    }
};