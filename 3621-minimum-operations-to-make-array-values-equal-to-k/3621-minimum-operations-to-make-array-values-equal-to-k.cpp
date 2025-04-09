class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        set<int>st;
        int i = n-1;
        
        sort(nums.begin(),nums.end());
        if(k>nums[0])return -1;
        while(i>=0){
            if(nums[i]>k){
                st.insert(nums[i]);
            }
            i--;
        }
        return st.size();
    }
};