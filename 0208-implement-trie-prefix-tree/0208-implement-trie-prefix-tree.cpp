class TrieNode{
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    // constructor
    TrieNode(char data){
        isTerminal = false;
        this->data = data;
        for(int i = 0;i<26;i++){
            children[i] = NULL;
        }
    }
};
class Trie {
public:
    void insertUtil(TrieNode* root,string word){
        if(word.size() == 0){
            root->isTerminal = true;
            return;
        }
        int indx = word[0]-'a';
        TrieNode* child;
        if(root->children[indx] != NULL){
            child = root->children[indx];

        }
        else{
            // abseth
            child = new TrieNode(word[0]);
            root->children[indx] = child;
        }
        insertUtil(child,word.substr(1));
    }
    bool searchUtil(TrieNode* root, string word){
        if(!root) return false;
        if(word.size() == 0){
            return  root->isTerminal;
        }
        int indx = word[0]-'a';
        return searchUtil(root->children[indx],word.substr(1));
    }
    bool startsWithUtil(TrieNode* root, string word){
        if(!root){
            return false;
        }
        if(word.size() == 0){
            return true;
        }
        int indx = word[0]-'a';
        return startsWithUtil(root->children[indx],word.substr(1));
    }
    TrieNode* root;
    Trie() {
        root = new TrieNode('/');
    }
    
    void insert(string word) {
        return insertUtil(root,word);
    }
    
    bool search(string word) {
        return searchUtil(root,word);
    }
    
    bool startsWith(string prefix) {
        return startsWithUtil(root,prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */