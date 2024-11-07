class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int siz = candidates.size();
        int largest_combination_size = 0;
        vector<int> bitInfo(32,0);
        for(auto ele: candidates){
            for(int i = 0;i<31;i++){
                if((ele & (1<<i))>0){
                    bitInfo[i]++;
                    largest_combination_size = max(largest_combination_size,bitInfo[i]);
                }
            }
        }

        return largest_combination_size;
    }
};