class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        // keep count of days left and right when no of guards are greater than that days
        int n = security.size();
        vector<int>left(n,0),right(n,0);
        for(int i = 1;i<n;i++){
            if(security[i]<= security[i-1]){
                left[i] += left[i-1]+1;
            }
        }
        for(int i= n-2;i>=0;i--){
            if(security[i] <= security[i+1]){
                right[i] += right[i+1]+1;
            }
        }
        vector<int>ans;
        for(int i = 0;i<n;i++){
            if(left[i]>= time && right[i] >= time)ans.push_back(i);
        }
        return ans;
    }
};