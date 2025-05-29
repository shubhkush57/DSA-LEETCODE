class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // only differe byone word only.. 
        // so make the all possible one differtn words and check them in the sequence..
        unordered_map<string,int>mp;
        for(auto it: wordList){
            mp[it]++;
        }
        queue<string>q;
        q.push(beginWord);
        unordered_map<string,int>vis;
        vis[beginWord]++;
        int level = 1;
        while(!q.empty()){
            int t = q.size();
            while(t--){
                string f = q.front();q.pop();
                if(f == endWord)return level;
                int siz = f.size();
                for(int i = 0;i<siz;i++){
                    char temp = f[i];
                    for(char c = 'a';c<='z';c++){
                        if(temp != c){
                            f[i] = c;
                            if(mp.count(f) && vis[f] == false){
                                q.push(f);
                                vis[f] = true;
                            }
                        }
                    }
                    f[i] = temp;
                }
                

            }
            level++;
        }

        return 0;
    }
};