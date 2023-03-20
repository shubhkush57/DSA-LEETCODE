class Solution {
public:
    int maxSatisfied(vector<int>& c, vector<int>& g, int m) {
        // Grumpy BookStore Owner.
        int n = c.size();
        // one wale minute extra add ho rahe h.
        int i = 0,j = 0;
        int ans = 0;
        int sat = 0;
        for(;i<n;i++){
            if(g[i] == 0){
                sat += c[i];
            }
        }
        i = 0;
        for(;j<m;j++){
            if(g[j] == 1){
                sat += c[j];
            }
        }
        ans = max(ans,sat);
        while(j<n){
            if(g[j] == 1){
                sat += c[j];
            }
            if(g[i] ==  1){
                sat -= c[i];
            }
            ans = max(ans,sat);
            i++;
            j++;
        }
        return ans;
    }
};