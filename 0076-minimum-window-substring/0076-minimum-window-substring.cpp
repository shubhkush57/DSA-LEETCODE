class Solution {
public:
    string minWindow(string s, string t) {
        // we can take the cases like..
        int n = s.size();
        string ans = "";
        unordered_map<char,int>mp;
        for(auto it: t){
            mp[it]++;
        }
        int count = mp.size();
        int first = -1,last = -1;
        int i = 0,j = 0;
        while(j<n){
            if(mp.count(s[j])){
                mp[s[j]]--;
                if(mp[s[j]] == 0){
                    count -=1;
                }
            }
            while(i<=j && count <= 0){
                if(first == -1 || (last-first+1)> (j-i+1)){
                    first = i;
                    last = j;
                }
                if(mp.count(s[i])){
                    mp[s[i]]++;
                    if(mp[s[i]] == 1){
                        count += 1;
                    }
                }
                i++;
            }

            j++;
        }
        return first == -1?"": s.substr(first,last-first+1);
        // each answer is unique.
    }
};

// a -> 2



