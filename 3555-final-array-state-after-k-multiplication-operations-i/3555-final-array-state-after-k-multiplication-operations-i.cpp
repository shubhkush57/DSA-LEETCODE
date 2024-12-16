class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        while(k>0){
            int min_ele_indx = min_element(nums.begin(),nums.end())-nums.begin();
            nums[min_ele_indx] = multiplier* nums[min_ele_indx];
            k--;
        }


        return nums;
    }
};