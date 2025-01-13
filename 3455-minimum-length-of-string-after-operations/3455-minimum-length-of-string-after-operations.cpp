class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        vector<int>count(26,0);
        for(auto it: s){
            count[it-'a']++;
        }
        int ans = 0;
        for(auto it:count){
            if(it != 0 ){
                if(it%2 == 0){
                    ans += 2;
                }
                else{
                    ans+= 1;
                }
            }
        }
        return ans;
    }
};