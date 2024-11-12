class TrieNode{
public:
    char ch;
    vector<TrieNode*>children;
    bool isWord;
    TrieNode(char c){
        this->ch = c;
        for(int i = 0;i<26;i++){
            this->children.push_back(NULL);
        }
        this->isWord = false;
    }
};
class Trie{
public:
    TrieNode* root;
    Trie(){
        root = new TrieNode('/');
    }
    void insert(string &word,TrieNode* root,int i){
        int n = word.size();
        if(i>=n){
            root->isWord = true;
            return;
        }

        TrieNode* child;
        char ch = word[i];
        if(root->children[ch-'a'] != NULL){
            child = root->children[ch-'a'];
        }
        else{
            child = new TrieNode(ch);
            root->children[ch-'a'] = child;
        }
        insert(word,child,i+1);
        return;
    }
    void insertWord(string &word){
        int n = word.size();
        TrieNode* r = root;
        insert(word,r,0);
        return;
    }
    // search for the word..
    bool search(string &word,TrieNode* root,int i){
        int n = word.size();
        if(i>=n)return true;
        //now we have to consider it as the 
        char ch = word[i];
        if(root->children[ch-'a'] == NULL)return false;
        return search(word,root->children[ch-'a'],i+1);
    }
    bool searchWord(string &word){
        TrieNode* r = root;
        return search(word,r,0);
    }
};
class Solution {
public:
    bool solve(string &s, int i,unordered_map<string,int>&mp,vector<int>&dp){
        // now we have to take the answer.
        int n = s.size();
        if(i>=n)return true;
        if(dp[i] != -1)return dp[i];
        bool ans = false;
        string re = "";
        for(int j = i;j<n;j++){
            re.push_back(s[j]);
            if(mp.count(re)){
                ans = ans or solve(s,j+1,mp,dp);
            }
        }
        return dp[i] = ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int>dp(n+1,false);
        dp[n] = true;
        unordered_map<string,int>mp;
        Trie* node = new Trie(); 
        for(auto it: wordDict){
            // mp[it]++;
            node->insertWord(it);
        }
        for(int i = n-1;i>=0;i--){
            bool ans = false;
            TrieNode* root = node->root;
            for(int j = i;j<n;j++){
                if(root->children[s[j]-'a'] == NULL)break;
                if(root->children[s[j]-'a']->isWord)
                ans = ans or dp[j+1];
                root = root->children[s[j]-'a'];
            }
            dp[i] = ans;
        }
        return dp[0];
    }
};
//
// Backtrack -> BF solution
// optimize it by take the index by partictions -> DP , map use
// second appraoch me -> trie use karna.
// now time to convert this solution to interative one.