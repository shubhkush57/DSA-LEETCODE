class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size();
        int m= queries.size();
        vector<int>ans(m);
        vector<int>maxi(n);
        int temp = INT_MIN;
        sort(items.begin(),items.end());
        for(int i = 0;i<n;i++){
            temp = max(temp,items[i][1]);
            maxi[i] = temp;
        }
        for(int i = 0;i<m;i++){
            int start=  0;
            int end = n-1;
            int temp = 0;
            while(start<=end){
                int mid = start+(end-start)/2;
                if(items[mid][0]<= queries[i]){
                    temp = maxi[mid];
                    start= mid+1;
                }
                else{
                    end = mid-1;
                }
            }
            ans[i] = temp;
        }
        return ans;
    }
};