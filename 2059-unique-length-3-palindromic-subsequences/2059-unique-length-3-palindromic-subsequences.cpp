class Solution {
public:
    int countPalindromicSubsequence(string s) {
        // no of unique characters in the 
        int n = s.size();
        vector<vector<int>>noOfUniqueCharacters(n,vector<int>(26,0));
        vector<bool>alreadyCalculated(26,false);
        vector<int>first(26,-1),last(26,-1);
        int ans = 0;
        vector<int>temp(26,0);
        for(int i = 0;i<n;i++){
            temp[s[i]-'a']++;
            noOfUniqueCharacters[i] = temp;
            // if(!alreadyCalculated[s[i]-'a']){
            //     alreadyCalculated[s[i]-'a'] = true;
            //     noOfUniqueCharacters[i] = (i == 0)?1:noOfUniqueCharacters[i-1]+1;
            // }
            // else
            // noOfUniqueCharacters[i] = noOfUniqueCharacters[i-1];

            if(first[s[i]-'a'] == -1)first[s[i]-'a'] = i;
            last[s[i]-'a']= i;
            // cout<<noOfUniqueCharacters[i]<<' ';
        }
        for(int i = 0;i<26;i++){
            if(first[i] != -1 && (last[i]-first[i]+1)>2){
                int temp = 0;
                for(int j = 0;j<26;j++){
                    temp += (noOfUniqueCharacters[last[i]-1][j] - noOfUniqueCharacters[first[i]][j])>0?1:0;
                    
                }
                ans += temp;
                cout<<i<<' '<<temp<<endl;
                // ans += noOfUniqueCharacters[last[i]-1]-noOfUniqueCharacters[first[i]];
            }
        }
        return ans;
    }
};