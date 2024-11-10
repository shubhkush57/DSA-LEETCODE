class Solution {
public:
    int characterReplacement(string s, int k) {
        // it continng the same letters....
        // so we have to start from the 
        int n = s.size();
        int ans = 0;
        // now we have to take the size.
        for(char ch = 'A';ch<='Z';ch++){
            int i = 0,j = 0;
            int repl = k;
            while(j<n){
                if(s[j] != ch){
                    k--;
                }
                while(i<j && k<0){
                    // now we hvae to remove the charactess...
                    if(s[i] != ch){
                        k++;
                    }
                    i++;
                }
                ans = max(ans,j-i+1);
                j++;
            }
            k = repl;
        }

        return ans;
    }
};