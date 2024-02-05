class TrieNode {
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
class Solution {
public:
    TrieNode *root;
    Solution(){
        root = new TrieNode();
    }
    ~Solution(){
        clear(root);
    }
    void clear(TrieNode* root){
        for(int i = 0; i < 26; i++){
            if(root->child[i]){
                clear(root->child[i]);
            }
        }
        delete(root);
    }
    void insert(string word){
        TrieNode *cur = root;
        for(auto w : word){
            if(cur->child[w - 'a'] == NULL){
                cur->child[w - 'a'] = new TrieNode();
            }
            cur = cur->child[w - 'a'];
        }
        cur->isWord = true;
    }
    string check(string word){
        TrieNode *cur = root;
        string s = "";
        for(auto i : word){
            if(cur->child[i - 'a'] == NULL) break;
            s += i;
            cur = cur->child[i - 'a'];
            if(cur->isWord) return s;
        }
        return word;
    }
    string replaceWords(vector<string>& dict, string sentence) {
        for(string s : dict) insert(s);
        istringstream ss(sentence);
        string word = "", res = "";
        while(ss>>word){
            res += check(word);
            res += ' ';
        }
        res.pop_back();
        return res;
    }
};