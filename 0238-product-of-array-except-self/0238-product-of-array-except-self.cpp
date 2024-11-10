class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // without division operations..
        int n = nums.size();
        vector<int>ans(n);
        // we have to return the answer...
        vector<int>pro_left(n,1);
        vector<int>pro_right(n,1);
        pro_left[0] = nums[0];
        pro_right[n-1]= nums[n-1];
        for(int i = 1;i<n;i++){
            pro_left[i] = pro_left[i-1]*nums[i];
        }
        for(int i = n-2;i>=0;i--){
            pro_right[i] = pro_right[i+1]*nums[i];
        }
        for(int i = 0;i<n;i++){
            int pro_ex = (i == 0)?1: pro_left[i-1];
            pro_ex *= (i == n-1)? 1: pro_right[i+1];
            ans[i] = pro_ex;

        }

        return ans;
    }
};