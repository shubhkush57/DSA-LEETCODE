class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>>ans;
        for(int i = 0;i<n-2;i++){
            int target = -nums[i]; // this is going to be mine target...
            if(i!= 0 && nums[i]== nums[i-1])continue;
            int start = i+1, end = n-1;
            while(start<end){
                int currentSum = nums[start]+nums[end];
                if(currentSum == target){
                    ans.push_back({nums[i],nums[start],nums[end]});
                    start++;
                    while(start<n && nums[start] == nums[start-1])start++;
                    end--;
                    while(end>=0 && nums[end] == nums[end+1])end--;
                    
                }
                else if(currentSum>target){
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