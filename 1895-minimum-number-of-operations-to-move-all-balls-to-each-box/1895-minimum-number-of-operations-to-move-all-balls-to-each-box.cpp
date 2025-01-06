class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int>ansLeft(n,0),ansRight(n,0);
        int o = 0;
        for(int i = 0;i<n;i++){
            ansLeft[i] = o+(i == 0?0:ansLeft[i-1]);
            if(boxes[i] == '1')o++;
        }
        o = 0;
        for(int i = n-1;i>=0;i--){
            ansRight[i] = o+(i == n-1?0:ansRight[i+1]);
            if(boxes[i] == '1')o++;
        }
        vector<int>ans(n,0);
        for(int i = 0;i<n;i++) ans[i] = ansLeft[i]+ansRight[i];
        return ans;

    }
};