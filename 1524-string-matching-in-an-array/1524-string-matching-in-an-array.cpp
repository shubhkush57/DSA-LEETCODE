class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string>ans;
        int n = words.size();
        for(int i = 0;i<n;i++){
            bool flag = false;
            for(int j = 0;j<n;j++){
                if(i != j){
                    for(int t = 0;t<words[j].size();t++){
                        
                        for(int k = t;k<words[j].size();k++){
                            if(words[j].substr(t,k-t+1) == words[i]){
                                // ans.push_back(words[i]); 
                                flag = true;
                                break;
                            }
                        }
                    }
                    
                }
            }
            if(flag)ans.push_back(words[i]);
        }
        return ans;
    }
};