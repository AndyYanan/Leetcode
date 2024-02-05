class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int len = candidates.size();
        dfs(candidates, target, 0, len);
        return res;
    }
    void dfs(vector<int>& A, int target, int startIdx, int len){
        if(target == 0){
            res.push_back(tmp);
            return;
        }

        for(int i = startIdx; i < len && target > 0; i++){
            tmp.push_back(A[i]);
            dfs(A, target-A[i], i, len);
            tmp.pop_back();
        }
        return;
    }
};
/*
// This class Solution implements a backtracking algorithm to find all possible combinations of elements
// from the given 'candidates' array that sum up to the 'target' value.

class Solution {
private:
    vector<vector<int>> res;   // Stores the resulting combinations.
    vector<int> tmpVec;         // Temporary vector to hold a combination during backtracking.

    // Backtracking function to explore combinations.
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex) {
        // If the current combination sums up to the target value, add it to the result.
        if(sum == target){
            res.push_back(tmpVec);
            return;
        }
        
        // Iterate through candidates starting from 'startIndex'.
        for(int i = startIndex; i < candidates.size() && candidates[i] + sum <= target; i++){
            sum += candidates[i];
            tmpVec.push_back(candidates[i]); // Include the current candidate in the combination.
            
            // Recursively call backtracking to explore further possibilities.
            backtracking(candidates, target, sum, i);
            
            // Remove the last candidate to backtrack and try other combinations.
            sum -= candidates[i];
            tmpVec.pop_back();
        }
    }

public:
    // Function to find all combinations that sum up to the 'target'.
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // Sort the candidates to optimize the search.
        backtracking(candidates, target, 0, 0);     // Start backtracking from the beginning.
        return res;                                 // Return the resulting combinations.
    }
};

*/