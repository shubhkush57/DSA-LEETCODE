class Solution {
public:
    bool detectCapitalUse(string word) {
        char s = word[0];
        int n = word.size();
        // if it is captail then
        if(isupper(s)){
            // if first letter is upper case
            string ne = word.substr(1,n-1);// now take this string 
            // cout<<ne<<endl;
            bool lower = true;
            bool upper = true;
            for(auto it: ne){
                if(isupper(it)){
                    lower = false;
                    // break;
                }
                if(islower(it)){
                    upper = false;
                }
            }
            return lower || upper;
        }
        else{
            // if first letter is lowercase then all the letter should be lower case
            for(auto it: word){
                if(isupper(it)){
                    return false;
                }
            }
        }
        return true;
    }
};