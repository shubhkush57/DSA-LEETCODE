class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int>maxChar(26,0);
        for(auto it: words2){
            // we have to count the total no 
            vector<int>charc(26,0);
            for(auto ch: it){
                charc[ch-'a']++;
                maxChar[ch-'a']= max(maxChar[ch-'a'],charc[ch-'a']);
            }
        }
        // issme mujhe maxneed of each character pata chali...
        vector<string>ans;
        for(auto it: words1){
            vector<int>charc(26,0);
            for(auto ch: it){
                charc[ch-'a']++;
            }
            bool flag = true;
            for(int i = 0;i<26;i++){
                if(charc[i]<maxChar[i]){
                    flag = false;break;
                }
            }
            if(flag)ans.push_back(it);
        }
        return ans;
    }
};