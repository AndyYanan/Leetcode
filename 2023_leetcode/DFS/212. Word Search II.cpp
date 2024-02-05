class TrieNode{
public:
    TrieNode *next[26];
    string word;
    TrieNode(){
        for(int i = 0; i < 26; i++){
            next[i] = NULL;
        }   
        word = "";
    }
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        TrieNode* root = buildTrie(words);
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                dfs(board, i, j, root, res);
            }
        }
        return res;
    }
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* p, vector<string>& res){
        char c = board[i][j];
        if(c == '#' || p->next[c - 'a'] == NULL) return;
        p = p->next[c - 'a'];
        if(p->word != ""){
            res.push_back(p->word);
            p->word = ""; // de-duplicate
        }
        board[i][j] = '#';
        if (i > 0) dfs(board, i - 1, j ,p, res); 
        if (j > 0) dfs(board, i, j - 1, p, res);
        if (i < board.size() - 1) dfs(board, i + 1, j, p, res); 
        if (j < board[0].size() - 1) dfs(board, i, j + 1, p, res); 
        board[i][j] = c;
    }
    TrieNode* buildTrie(vector<string>& words){
        TrieNode* root = new TrieNode();
        for(string w:words){
            TrieNode *p = root;
            for(char c:w){
                int i = c - 'a';
                if(p->next[i] == NULL){
                    p->next[i] = new TrieNode();
                }
                p = p->next[i];
            }
            p->word = w;
        }
        return root;
    }
};