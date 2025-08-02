class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int>mp;
        unordered_map<string,int>vis;
        for(auto word: wordList)mp[word]++;
        vis[beginWord]++;
        queue<string>q;
        q.push(beginWord);
        int level = 1;
        while(!q.empty()){
            int t = q.size();
            while(t--){
                string temp = q.front();q.pop();
                if((temp == endWord))return level;
                for(int i = 0;i<temp.size();i++){
                    char p = temp[i];
                    for(char ch = 'a';ch<='z';ch++){
                        if(p != ch){
                            temp[i] = ch;
                            if(!vis.count(temp) && mp.count(temp)){
                                q.push(temp);
                                vis[temp]++;
                            }
                        }
                    }
                    temp[i] = p;
                }
            }
            level++;
        }
        return 0;
    }
};