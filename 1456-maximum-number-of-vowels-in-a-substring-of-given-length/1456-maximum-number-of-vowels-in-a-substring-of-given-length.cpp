class Solution {
public:
    int maxVowels(string s, int k) {
        int ans = 0;
        int n = s.size();
        int i = 0,j = 0;
        int countV = 0;
        for(;j<k;j++){
            if(s[j] == 'a'|| s[j] == 'e' ||s[j] == 'i' || s[j] == 'o' || s[j] == 'u'){
                countV++;
            }
        }
        ans = max(ans,countV);
        while(j<n){
            if(s[j] == 'a'|| s[j] == 'e' ||s[j] == 'i' || s[j] == 'o' || s[j] == 'u'){
                countV++;
            }
            if(s[i] == 'a'|| s[i] == 'e' ||s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                countV--;
            }
            ans = max(ans,countV);
            j++;
            i++;
        }
        return ans;
    }
};