class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxOnes = 0,countConsectiveOnes = 0;
        for(auto num : nums){
            if(num == 0){
                countConsectiveOnes = 0;
            }
            else{
                countConsectiveOnes += 1;
            }
             maxOnes = max(maxOnes,countConsectiveOnes);
        }
        return maxOnes;
    }
};