class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        // we will take the maximum jump from the past.
        int reach = 0;
        for(int i = 0;i<n;i++){
            reach = max(reach,i+nums[i]);
            if(reach == n-1)return true;
            if(reach == i)return false;
        }
        return true;
    }
};