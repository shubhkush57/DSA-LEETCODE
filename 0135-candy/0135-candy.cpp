class Solution {
public:
    int candy(vector<int>& ratings) {
        // first give one candy to each one..
        int n = ratings.size();
        vector<int>right(n,1),left(n,1);
        for(int i = 1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                left[i] += left[i-1];
            }
        }
        for(int i = n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                right[i] += right[i+1];
            }
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            ans += max(left[i],right[i]);
        }
        return ans;

    }
};