class TrieNode{
public:
    char data;
    TrieNode* children[26];
    bool isword;
    TrieNode(char d){
        data = d;
        for(int i = 0;i<26;i++){
            children[i] = NULL;
        }
        isword = false;
    }
};

class WordDictionary {
public:
    void insert(TrieNode* root, string &word,int i){
        if(!root ){
            return;
        }
        if(word.size() == i){
            root->isword = true;
            return;
        }
        int ind = word[i] -'a';
        TrieNode*child;
        if(root->children[ind] != NULL){
            // already present
            child = root->children[ind];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[ind] = child;
        }
        insert(child,word,i+1);
        return;
    }
    bool searchUtil(TrieNode* root, string &word,int i){
        if(!root){
            return false;
        }
        if(word.size() == i){
            return root->isword;
        }
        char ch = word[i];
        if(ch != '.'){
            int ind = ch-'a';
            return searchUtil(root->children[ind],word,i+1);
        }
        // now if it si . then we will be matching with each character
        bool ans = false;
        for(int j= 0;j<26;j++){
            if(root->children[j] != NULL){
                ans = ans || searchUtil(root->children[j],word,i+1);
            }
        }
        return ans;
    }
    TrieNode* root;

    WordDictionary() {
        root = new TrieNode('/');
    }
    
    void addWord(string word) {
        int i = 0;
        insert(root,word,i);
        return;
    }
    
    bool search(string word) {
        // search for the word if it is coming word if it is prsenet or not
        int i = 0;
        return searchUtil(root,word,i);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */