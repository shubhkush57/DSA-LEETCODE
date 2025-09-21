class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int ans = 0;
        for(char ch = 'A';ch<='Z';ch++){
            // we are searching for the s
            int i = 0,j = 0,k_= k;
            while(j<n){
               if(s[j] != ch){
                 k_--;
               }
               while(i<j && k_<0){
                    if(s[i] != ch){
                        k_++;
                    }
                    i++;
               }
                ans = max(ans,j-i+1);
               j++;

            }
        }

        return ans;
    }
};