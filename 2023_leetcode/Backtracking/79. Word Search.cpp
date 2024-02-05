class Solution {
public:
    // Function to check if a word exists in a 2D board using DFS
    bool exist(vector<vector<char>>& board, string word) {
        if (word == "") return false; // Empty word has no existence
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                // If the first character of the word matches the current board cell
                if (board[i][j] == word[0] && dfsSearch(board, i, j, word, 0)) {
                    return true; // Word found
                }
            }
        }    
        return false; // Word not found
    }
    
    // Recursive DFS search function
    bool dfsSearch(vector<vector<char>>& board, int i, int j, string word, int idx) {
        // If entire word has been matched, return true
        if (idx == word.size()) {
            return true;
        }
        // If current cell is out of bounds, return false
        if (i >= board.size() || j >= board[0].size() || i < 0 || j < 0) {
            return false;
        }

        // If current cell's character doesn't match the word's character
        if (board[i][j] != word[idx]) {
            return false;
        }
        
        // Mark the current cell as visited
        board[i][j] = '*';
        
        // Explore adjacent cells in a recursive manner
        bool status = dfsSearch(board, i + 1, j, word, idx + 1) ||
                      dfsSearch(board, i - 1, j, word, idx + 1) ||
                      dfsSearch(board, i, j + 1, word, idx + 1) ||
                      dfsSearch(board, i, j - 1, word, idx + 1);
        
        // Restore the original character in the current cell
        board[i][j] = word[idx];
        
        return status; // Return the status of search
    }
};
