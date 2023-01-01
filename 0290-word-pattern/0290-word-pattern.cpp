class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int m = pattern.size();
        int n = s.size();
        unordered_map<char,string>mp;
        unordered_map<string,char>mp2;
        int i = 0;
        int j = 0;
        string re = "";
        while(i<m && j< n){
            if(s[j] == ' '){
                if(mp.count(pattern[i])){
                    if(mp[pattern[i]] != re){
                        return false;
                    }
                }
                else{
                    mp[pattern[i]] = re;
                }
                
                
                if(mp2.count(re)){
                    if(mp2[re] != pattern[i]){
                        return false;
                    }
                }
                else{
                    mp2[re] = pattern[i];
                }
                re = "";
                i++;
            }
            else if(j == n-1){
                re.push_back(s[j]);
                if(mp.count(pattern[i])){
                    if(mp[pattern[i]] != re){
                        return false;
                    }
                }
                else{
                    mp[pattern[i]] = re;
                }
                 if(mp2.count(re)){
                    if(mp2[re] != pattern[i]){
                        return false;
                    }
                }
                else{
                    mp2[re] = pattern[i];
                }
                re = "";
                i++;
            }
            else{
                // working in the different values
                re.push_back(s[j]);
            }
            j++;
        }
        // cout<<i<<' '<<j<<endl;
        // cout<<m<<' '<<n<<endl;
        // for(auto it: mp){
        //     cout<<it.first<<' '<<it.second<<endl;
        // }
        if(i != m || j != n){
            return false;
        }
        return true;
    }
};