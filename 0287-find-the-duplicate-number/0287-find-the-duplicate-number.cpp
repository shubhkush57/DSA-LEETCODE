class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        /*Lableing stargety.. where I label things and if I got already item labeled it means there were duplications..
        */
        int n = nums.size();
        for(int i = 0;i<n;i++){
            int val = abs(nums[i]);
            if(nums[val]<0) return val;
            nums[val] = -nums[val];
        }
        return -1;
    }
};