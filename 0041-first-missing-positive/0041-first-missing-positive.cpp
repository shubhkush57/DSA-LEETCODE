class Solution {
public:
    #define int2 long long
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i<n;i++){
            if(nums[i]<=0 || nums[i]>n)continue;
            int ele = nums[i], dest_indx = ele-1,curr = i;
            while(ele>0 && ele<n && nums[curr] != nums[dest_indx]){
                int temp = nums[dest_indx];
                nums[dest_indx] = ele;
                nums[curr] = temp;
                curr = i;
                ele = nums[curr];
                dest_indx = ele-1;

            }
        }
        for(int i = 0;i<n;i++){
            if(nums[i] != i+1)return i+1;
        }
        return n+1;
    }
};