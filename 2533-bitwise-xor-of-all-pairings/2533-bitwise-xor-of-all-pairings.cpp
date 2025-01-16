class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(m%2 == 0 && n%2 ==0){
            return 0;
        }
        else if(m%2 ==0 && n%2 != 0){
            int ans  =0;
            for(int i = 0;i<m;i++){
                ans = ans^nums1[i];
            }
            return ans;
        }
        else if(m%2 !=0 && n%2 == 0){
            int ans = 0;
            for(int i = 0;i<n;i++){
                ans = ans^nums2[i];
            }
            return ans;
        }
        else if(m%2 !=0 && n%2 != 0){
            int ans = 0;
            for(int i = 0;i<m;i++){
                ans = ans^nums1[i];
            }
            for(int i = 0;i<n;i++){
                ans = ans^nums2[i];
            }
            return ans;
        }
        return 0;
    }
};