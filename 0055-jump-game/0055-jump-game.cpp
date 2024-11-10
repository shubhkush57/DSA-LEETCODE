class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int gas = 0;
        for(auto it: nums){
            if(gas<0)return false;
            else if(it>gas)gas = it;
            gas -=1;
        }
        return true;
    }
};