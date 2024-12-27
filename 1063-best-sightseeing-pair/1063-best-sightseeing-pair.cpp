class Solution {
public:
    int x = 5;
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int ans = 0,maxi = values[0];
        for(int i = 1;i<n;i++){
            ans = max(ans,maxi+values[i]-i);
            maxi = max(maxi,values[i]+i);
        }
        return ans;
    }
};