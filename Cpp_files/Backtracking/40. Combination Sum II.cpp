// This class Solution implements a backtracking algorithm to find all unique combinations of elements
// from the given 'candidates' array that sum up to the 'target' value.

class Solution {
public:
    vector<vector<int>> res;    // Stores the resulting combinations.
    vector<int> tmpVec;          // Temporary vector to hold a combination during backtracking.
    
    // Function to find all unique combinations that sum up to the 'target'.
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // Sort the candidates to optimize the search.
        backTrackingSum(candidates, target, 0, 0);  // Start backtracking from the beginning.
        return res;                                 // Return the resulting combinations.
    }
    
    // Backtracking function to explore unique combinations.
    void backTrackingSum(vector<int>& candidates, int target, int startIdx, int sum){
        if(sum == target){
            res.push_back(tmpVec);
            return;
        }
        
        for(int i = startIdx; i < candidates.size() && candidates[i] + sum <= target; i++){
            // Skip duplicates to avoid duplicate combinations.
            if(i > startIdx && candidates[i - 1] == candidates[i]){
                continue;
            }
            
            sum += candidates[i];
            tmpVec.push_back(candidates[i]); // Include the current candidate in the combination.
            
            // Recursively call backtracking to explore further possibilities.
            backTrackingSum(candidates, target, i + 1, sum);
            
            // Remove the last candidate to backtrack and try other combinations.
            sum -= candidates[i];
            tmpVec.pop_back();
        }
    }

    /*
    vector<vector<int>> res;
    vector<int> tmpVec;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // Sort the candidates to optimize the search.
        dfs(candidates, 0, candidates.size(), target);
        return res;
    }
    void dfs(vector<int>& candidates, int begin, int end, int target){
        if(target == 0){
            res.push_back(tmpVec);
            return ;
        }
        for(int i = begin; i < end && target > 0; i++){
            if(i > begin && candidates[i-1]==candidates[i]) continue;
            tmpVec.push_back(candidates[i]);
            dfs(candidates, i+1, end, target - candidates[i]);
            tmpVec.pop_back();
        }
    }
    */
};
