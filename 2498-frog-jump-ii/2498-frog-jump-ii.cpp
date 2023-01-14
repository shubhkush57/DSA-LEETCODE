class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n = stones.size();
        // jump on every alternating stone
        int ans = 1;
        int i = 0;
        int prev = 0;
        while(i<n){
            i += 2;
            if(i<n){
                ans = max(ans,stones[i]-stones[prev]);
                prev = i;
            }
            else{
                ans = max(ans,stones[n-1]-stones[n-2]);
            }
        }
        reverse(stones.begin(),stones.end());
        i = 0;
        prev = 0;
        if(n%2 == 0){
            while(i<n){
                i += 2;
                if(i<n){
                    ans = max(ans,abs(stones[i]-stones[prev]));
                    prev = i;
                }
                else{
                    ans = max(ans,abs(stones[n-1]-stones[n-2]));
                }
            }
        }
        else{
            ans = max(ans,abs(stones[0]-stones[1]));
            i++;
            prev = i;
            while(i<n){
                i += 2;
                if(i<n){
                    ans = max(ans,abs(stones[i]-stones[prev]));
                    prev = i;
                }
                else{
                    ans = max(ans,abs(stones[n-1]-stones[n-2]));
                }
            }
        }
        
        
        return ans;
    }
};