class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        // we have to make a bit count
        vector<int>bit_count(32,0);
        int ans = INT_MAX;
        int currentOr = 0;
        int left = 0;
        for(int i = 0;i<n;i++){
            int val = nums[i];
            currentOr = currentOr | val;
            // cout<<currentOr<<endl;
            for(int j = 0;j<32;j++){
                if((val & (1<<j))>0){
                    bit_count[j]++;
                }
            }
            while(left<=i && currentOr >=k){
                ans = min(ans,i-left+1);
                val = nums[left];
                for(int j = 0;j<32;j++){
                    if((val & (1<<j))>0){
                        bit_count[j]--;
                        if(bit_count[j] == 0){
                            currentOr  = currentOr & ~(1<<j);
                        }
                    }
                }
                left++;
            }
            

        }

        return ans == INT_MAX?-1: ans;
    }
};