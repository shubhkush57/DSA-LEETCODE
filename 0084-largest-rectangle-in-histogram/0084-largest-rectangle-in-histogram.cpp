class Solution {
public:
    vector<int> funcLeftMin(vector<int>&heights){
        int n = heights.size();
        vector<int>ans(n,0);
        stack<int>stk;
        for(int i = 0;i<n;i++){
            while(!stk.empty() && heights[i]<= heights[stk.top()]){
                stk.pop();
            }
            if(!stk.empty()){
                ans[i] = stk.top()+1;
            }

            stk.push(i);
        }
        return ans;
    }
    vector<int> funcRightMin(vector<int>&heights){
        int n = heights.size();
        vector<int>ans(n,n-1);
        stack<int>stk;
        for(int i = n-1;i>=0;i--){
            while(!stk.empty() && heights[i]<= heights[stk.top()]){
                stk.pop();
            }
            if(!stk.empty()){
                ans[i] = stk.top()-1;
            }
            stk.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        vector<int>leftMinIndx = funcLeftMin(heights);
        vector<int>rightMinIndx = funcRightMin(heights);
        for(int i = 0;i<n;i++){
            int area = (rightMinIndx[i]-leftMinIndx[i]+1)*heights[i];
            ans = max(ans,area);
        }
        return ans;
    }
};