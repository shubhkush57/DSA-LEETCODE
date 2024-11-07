class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int largest_combination_size = 0;
        vector<int> bitInfo(32,0);
        for(int i = 0;i<31;i++){
            int count = 0;
            for(auto ele: candidates){
                if((ele & (1<<i))>0){
                    count++;
                    largest_combination_size = max(largest_combination_size,count);
                }
            }
        }
        return largest_combination_size;
    }
};