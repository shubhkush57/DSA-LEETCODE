class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans(n+1,0);
        for(int i = 0;i<=n;i++){
            // now for each i we have to go and find how many set bits are present here.
            int set_bits = 0;
            for(int j = 0;j<32;j++){
                if((i & (1<<j))>0)set_bits++;
            }
            ans[i] = set_bits;
        }
        return ans;
    }
};