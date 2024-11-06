class Solution {
public:
    bool canSortArray(vector<int>& nums) {
       int prevMax = INT_MIN;
       int n = nums.size();
       int curMin = nums[0],curMax = nums[0];
       int setBits = __builtin_popcount(nums[0]);
       for(int i = 1;i<n;i++){
            if(setBits ==  __builtin_popcount(nums[i])){
                curMin = min(curMin,nums[i]);
                curMax  = max(curMax,nums[i]);
            }
            else{
                // now it's not equal .. now we should move on check if nums[i]> prevMax
                if(curMin< prevMax){
                    return false;
                }
                prevMax = curMax;
                setBits =  __builtin_popcount(nums[i]);
                curMax = nums[i];
                curMin = nums[i];
               
            }
       }

       return curMin>prevMax;
    }
};