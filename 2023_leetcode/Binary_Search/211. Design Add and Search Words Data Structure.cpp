class TrieNode{
public:
    bool isWord;
    TrieNode* child[26];
    TrieNode(){
        isWord = false;
        for(int i = 0; i < 26; i++){
            child[i] = NULL;
        }
    }
};
class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for(char &c : word){
            if(node->child[c - 'a'] == NULL){
                node->child[c - 'a'] = new TrieNode();
            }
            node = node->child[c - 'a'];
        }
        node->isWord = true;
    }
    
    bool search(string word) {
        return searchWord(word, root);
    }

    bool searchWord(string word, TrieNode* node){
        for(int i = 0; i < word.size(); ++i){
            char c = word[i];
            if(c == '.'){
                for(auto ch : node->child){
                    if(ch && searchWord(word.substr(i+1), ch)){
                        return true;
                    }
                }
                 return false;
            }
            if(node->child[c - 'a'] == NULL) return false;
            node = node->child[c - 'a'];
        }
        return node && node->isWord;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */ 