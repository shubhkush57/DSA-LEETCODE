class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        unordered_map<char,int>mp;
        for(auto it: t)mp[it]++;
        int reqChar = mp.size();
        int left = 0, right = 0, size = INT_MAX, start = 0;
        while(right<m){
            if(mp.count(s[right])){
                mp[s[right]]--;
                if(mp[s[right]]==0){
                    reqChar--;
                }
            }
            while(left<=right && reqChar == 0){
                if(size>(right-left+1)){
                    size = right-left+1;
                    start = left;
                }
                if(mp.count(s[left])){
                    mp[s[left]]++;
                    if(mp[s[left]] == 1)reqChar++;
                }
                left++;
            }
            right++;
        }
        return size == INT_MAX?"": s.substr(start,size);
    }
};