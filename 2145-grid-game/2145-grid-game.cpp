class Solution {
public:
    #define int2 long long
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<int2> prefix1(n),prefix2(n);
        prefix1[0] = grid[0][0];
        prefix2[0] = grid[1][0];
        for(int i = 1;i<n;i++){
           
                prefix1[i] = prefix1[i-1]+grid[0][i];
                prefix2[i] = prefix2[i-1]+grid[1][i]; 
        }
        int2 ans = LLONG_MAX;
       
        for(int i = 0;i<n;i++){

            int2 f1 = (i == n-1)?0:(prefix1[n-1]-prefix1[i]);
            int2 f2 = (i == 0)?0:prefix2[i-1];
            ans = min(ans,max(f1,f2));
        }
        return ans;
    }
};