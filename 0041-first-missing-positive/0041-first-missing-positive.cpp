class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        

        // swap , take the next will keep it swapping in ti's correct postion
        // if resulting of the array size or it'is in correct
        int n = nums.size();
        for(int i = 0;i<n;i++){
            // each element
            // element if it's greater thatns ize..
            if(nums[i]> n || nums[i]<=0){
                continue;
            }
            else{
                int ele = nums[i];
                int des_indx = ele-1;
                int curr = i;
                while(ele < n && ele >0 && nums[curr] != nums[des_indx]){
                    // swap the number
                    int ele_pres = nums[des_indx];
                    nums[des_indx] = ele;
                    nums[curr] = ele_pres;
                    ele = nums[curr];
                    curr = i;
                    des_indx = nums[curr]-1;
                }
            }
        }
        int ans = 1;
        for(int i = 0;i<n;i++){
            if(nums[i] != ans){
                return ans;
            }
            ans++;
        }
        return ans;
    }
};