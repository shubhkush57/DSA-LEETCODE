class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // unordered_set<int> numSet(nums.begin(), nums.end());
        // int longest = 0;

        // for (int num : numSet) {
        //     if (numSet.find(num - 1) == numSet.end()) {
        //         int length = 1;
        //         while (numSet.find(num + length) != numSet.end()) {
        //             length++;
        //         }

        //         longest = max(longest, length);
        //     }
        // }

        // return longest;
        int n = nums.size();
        unordered_set<int>st(nums.begin(),nums.end());
        int longest = 0;
        for(auto num: st){
            if(!st.count(num+1)){
                int length  = 1;
                while(st.count(num-length)){
                    length++;
                }
                longest = max(longest,length);
            }
        }

        return longest;
    }
};