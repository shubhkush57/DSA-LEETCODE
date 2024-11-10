class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans; // answer array
        sort(nums.begin(),nums.end()); // sorting the array
        // they should not contiain duplicates..
        for(int i = 0;i<n;i++){
            if(i>0 && nums[i] == nums[i-1])continue;
            int target = -nums[i];
            int start  = i+1;
            int end = n-1;
            // we will be seraching the each element..
            while(start<end){
                int currSum = nums[start]+nums[end];
                if(currSum == target){
                    // we have out answer...
                    ans.push_back({nums[i],nums[start],nums[end]});
                    start++;
                    while(start<n && nums[start] == nums[start-1]){
                        start++;
                    }
                    end--;
                    while(end>=0 && nums[end] == nums[end+1]){
                        end--;
                    }
                }
                else if(currSum>target){
                    end--;
                }
                else{
                    start++;
                }
            }
        }
        return ans;
    }
};