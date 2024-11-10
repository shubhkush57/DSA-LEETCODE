class Solution {
public:
    #define int2 long long
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int2 largest_sum = LLONG_MIN;
        int2 curr_sum = 0L;
        for(int i = 0;i<n;i++){
            if(curr_sum+nums[i]<=nums[i]){
                curr_sum = nums[i];
            }
            else{
                curr_sum += (int2)nums[i];
            }
            largest_sum = max(largest_sum,curr_sum);
        }
        return largest_sum;

    }
};