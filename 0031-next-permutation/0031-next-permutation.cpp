class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind1 = -1;
        for(int i = n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                ind1 = i;
                break;
            }
        }
        if(ind1 == -1){
            reverse(nums.begin(),nums.end());return;
        }
        // we have found some index... we have to swap with
        for(int i = n-1;i>ind1;i--){
            if(nums[i]>nums[ind1]){
                swap(nums[i],nums[ind1]);
                break;
            }
        }
        sort(nums.begin()+ind1+1,nums.end());
        return;
    }
};