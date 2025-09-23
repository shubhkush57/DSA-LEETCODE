class TrieNode{
    public:
        char val;
        vector<TrieNode*> children;
        bool isWord;
        TrieNode(char val){
            this->val = val;
            this->isWord = false;
            for(int i = 0;i<26;i++){
                children.push_back(NULL);
            }
        }
};

class Trie {
public:
    TrieNode* node = new TrieNode('/');
    Trie() {
        
    }
    void insertWord(string &word,int i,TrieNode* node){
        int n = word.size();
        if(i>=n){
            node->isWord = true;
            return;
        }
        char temp = word[i];
        TrieNode* child;
        if(node->children[temp-'a'] == NULL){
            child = new TrieNode(temp);
        }
        else{
            child = node->children[temp-'a'];
        }
        node->children[temp-'a'] = child;
        insertWord(word,i+1,child);
    }
    void insert(string word) {
        TrieNode* newNode = node;
        insertWord(word,0,newNode);
        return;
    }
    
    bool search(string word) {
        TrieNode* newNode = node;
        return searchWord(word,0,newNode);
    }
    bool searchWord(string &word,int i,TrieNode* node){
        int n = word.size();
        if(i>=n){
            return node->isWord;
        }
        char temp = word[i];
        if(node->children[temp-'a'] == NULL)return false;
        return searchWord(word,i+1,node->children[temp-'a']);
    }
    bool startsWithWord(string &word,int i,TrieNode* node){
        int n = word.size();
        if(i>=n){
            return true;
        }
        char temp = word[i];
        if(node->children[temp-'a'] == NULL)return false;
        return startsWithWord(word,i+1,node->children[temp-'a']);
    }
    bool startsWith(string prefix) {
        TrieNode* newNode = node;
        return startsWithWord(prefix,0,newNode);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */