class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int siz = queries.size();
        int n = words.size();
        vector<char>vowels = {'a', 'e', 'i', 'o','u'};
        vector<int>countString(n,0);
        vector<int>ans;
        for(int i = 0;i<n;i++){
            string it = words[i];
            int strSiz = it.size();
            bool startingStr = false;
            bool endingStr = false;
            for(auto v: vowels){
                if(v == it[0]){
                    startingStr = true;
                }
                if(v == it[strSiz-1]){
                    endingStr = true;
                }
            }
            if(endingStr && startingStr){

                countString[i] = (i==0)?1: countString[i-1]+1;
            }
            else{
                countString[i] = (i==0)?0: countString[i-1];
            }
        }
        for(auto it: queries){
            int s = it[0],e =it[1];
            int temp = (s == 0)?countString[e]: countString[e]-countString[s-1];
            ans.push_back(temp);
        }
        return ans;
    }
};