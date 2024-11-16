class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 1;i<n-1;i++){
            swap(nums[i],nums[i+1]);
            i++;
        }
        return nums;
        
    }
};