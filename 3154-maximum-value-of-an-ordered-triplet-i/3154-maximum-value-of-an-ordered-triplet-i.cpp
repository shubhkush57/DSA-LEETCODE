class Solution {
public:
    #define int2 long long
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        int2 ans = 0L;
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                for(int k = j+1;k<n;k++){
                    ans = max(ans,(nums[i]-nums[j])*(int2)nums[k]);
                }
            }
        }
        return ans;
    }
};