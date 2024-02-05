class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;    // Vector to store resulting combinations
        vector<int> tmpcomb;        // Temporary vector to store combinations during DFS
        dfs(res, tmpcomb, 1, k, n);  // Start DFS from index 1
        return res;                 // Return the final list of combinations
    }

    void dfs(vector<vector<int>>& res, vector<int>& tmpcomb, int startIdx, int k, int n){
        if(k == 0){                  // Base case: combination of size k reached
            res.push_back(tmpcomb);  // Include the current combination in the result
            return;
        }

        for(int i = startIdx; i <= (n - k + 1); ++i){
            tmpcomb.push_back(i);    // Include current element in the combination
            dfs(res, tmpcomb, i+1, k-1, n);  // Recursive call to explore combinations
            tmpcomb.pop_back();      // Backtrack by removing the current element
        }
    }
};
