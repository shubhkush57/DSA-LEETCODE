class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int>re;
        int sum = 0;
        int ans = 0;
        bool zero = false;
        for(int i = 0;i<n;i++){
            if(nums[i] == 0) {
                re.push_back(0);
            }
            else if(nums[i] == 1 ){
                sum += 1;
                if(i == n-1 || nums[i+1] == 0){
                    re.push_back(sum);
                    sum = 0;
                }
            }
            if(nums[i] == 0){
                zero = true;
            }
        }
        
        n = re.size();
        if(n == 1){
            if(zero == false){
                return re[0]-1;
            }
            return re[0];
        }
        for(int i = 0;i<n;i++){
            if(re[i] == 0){
                if(i == 0 ){
                    ans = max(ans,re[i+1]);
                }
                else if(i == n-1){
                    ans = max(ans,re[i-1]);
                }
                else{
                    ans = max(ans,re[i-1]+re[i+1]);
                }
            }
        }
        return ans;
    }
};