class Solution {
public:
#define pp pair<int,int>
#define int2 long long int
#define minHeap priority_queue<pp,vector<pp>,greater<pp>>
#define sec second
#define fi  first
#define umapset unordered_map<int,set<int>>
#define repin for(int i = 0;i<n;i++)



    int numberOfSubstrings(string s) {
        int n = s.size();
        unordered_map<char,int>mp;
        int ans =0;
        int i = 0;
        int j = 0;
        while(j<n){
            if(mp.size() <3){
                mp[s[j]]++;
                while(mp.size() == 3){
                    ans += n-j;
                    mp[s[i]]--;
                    if(mp[s[i]] == 0){
                        mp.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};