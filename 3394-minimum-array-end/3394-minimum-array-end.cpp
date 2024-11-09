class Solution {
public:
    #define int2 long long
    long long minEnd(int n, int x) {
        int2 X = x;
        int2 N = n-1;
        int i = 0,j = 0;
        int2 ans = 0;
        while(i<64){
            if((X & (1LL<<i))>0){
                ans = ans | (1LL<<i);
            }
            else{
                // if it is zero...
                if((N & (1LL<<j))>0){
                    ans = ans | (1LL<<i);
                }
                j++;
            }
            i++;
        }
        return ans;
    }
};