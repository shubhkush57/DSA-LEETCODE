class Solution {
public:
    string reorganizeString(string s) {
        // check if maxFreq ele count is less than size+1/2 , otherwise NP; and place at alernative place ... and if they are exceeding size , start from 1;
        unordered_map<char,int>mp;
        int n = s.size();
        int maxCount = 0,maxEle = '.';
        for(auto it: s){
            mp[it]++;
            if(mp[it]>maxCount){
                maxCount = mp[it];
                maxEle = it;
            }
        }
        // now we have to find
        if(maxCount>(n+1)/2) return "";
        int j = 0;
        while(mp[maxEle]>0){
            s[j] = maxEle;
            j+=2;
            mp[maxEle]--;
        }
        
        for(auto it: mp){
           
            while(mp[it.first]>0){
                if(j>=n){
                    j = 1;
                }
                 s[j] = it.first;
                 mp[it.first]--;
                 j+=2;   
            }
        }
        return s;

    }
};