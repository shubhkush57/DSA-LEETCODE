class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        stack<int>stk;
        map<int,int>store;
        for(int i = n-1;i>=0;i--){
            while(!stk.empty() && nums2[i]>= nums2[stk.top()]){
                stk.pop();
            }
            if(stk.empty())store[nums2[i]] = -1;
            else store[nums2[i]] = nums2[stk.top()];
            stk.push(i);
            
        }
        for(int i = 0;i<nums1.size();i++){
            nums1[i] = store[nums1[i]];
        }
        return nums1;

    }
};