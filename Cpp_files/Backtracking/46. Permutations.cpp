class Solution {
public:
    // Function to generate all permutations of a given vector of integers
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        dfs(res, 0, nums);
        return res;
    }

    // Helper function to perform depth-first search (DFS) for permutations
    void dfs(vector<vector<int>>& res, int begin, vector<int>& nums) {
        if (begin == nums.size()) {
            res.push_back(nums); // If the current permutation is complete, add it to the result
            return;
        }

        for (int i = begin; i < nums.size(); ++i) {
            swap(nums[begin], nums[i]); // Swap the current element with each element after it
            dfs(res, begin + 1, nums); // Recursively find permutations for the remaining elements
            swap(nums[begin], nums[i]); // Backtrack by swapping back to the original order
        }
    }
};
