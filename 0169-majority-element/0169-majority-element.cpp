class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int winner = nums[0];
        int vote = 1;
        for(int i = 1;i<nums.size();i++){
            if(nums[i] != winner){
                vote --;
            }
            else vote++;
            if(vote == 0){
                winner = nums[i];
                vote = 1;
            }
        }
        return winner;
    }
};