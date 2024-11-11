class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        // return the number which is missing from teh array.
        // we have to return 
        int sum = accumulate(nums.begin(),nums.end(),0);
        int reqSum = (n*(n+1))/2;
        return reqSum - sum;
    }
};