class TrieNode{
public:
    bool is_word;
    TrieNode *childs[26];

    TrieNode(){
        is_word = false;
        for(int i = 0; i < 26; ++i){
            childs[i] = NULL;
        }
    }
};

class Trie {
private:    
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    ~Trie(){
        clear(root);
    }
    void clear(TrieNode* root){
        for(int i = 0; i < 26; ++i){
            if(root->childs[i] != NULL){
                clear(root->childs[i]);
            }
        }
        delete root;
    }
    
    void insert(string word) { 
        TrieNode* curr = root;
        for(char c:word){
            if(curr->childs[c-'a'] == NULL){
                curr->childs[c-'a'] = new TrieNode();
            }
            curr = curr->childs[c-'a'];
        }
        curr->is_word = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(char c:word){
            if(curr->childs[c-'a'] == NULL){
                return false;
            }
            curr = curr->childs[c-'a'];
        }
        return curr->is_word;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(char c:prefix){
            if(curr->childs[c-'a'] == NULL){
                return false;
            }
            curr = curr->childs[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */