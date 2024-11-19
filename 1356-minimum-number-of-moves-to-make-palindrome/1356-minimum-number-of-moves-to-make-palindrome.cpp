class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        // s a pailindrome..
        int ans = 0;
        int n = s.size();
        int i = 0,j = n-1;
        while(i<=j){
            if(s[i] != s[j]){
                // we need to swap the element..
                int k1 = i+1;
                while(k1<n && s[k1] != s[j]){
                    k1++;
                }
                
                int k2 = j-1;
                while(k2>=0 && s[k2] != s[i]){
                    k2--;
                }
                
                // which one is less
                int m1 = k1-i;
                int m2 = j-k2;
                if(m1<=m2){
                    ans += m1;
                    // swap the elemnt.
                    while(m1--){
                        swap(s[k1],s[k1-1]);
                        k1--;
                    }
                }
                else{
                    ans += m2;
                    while(m2--){
                        swap(s[k2],s[k2+1]);
                        k2++;
                    }
                }
                
            }
            i++;
            j--;
        }
        return ans;
    }
};