class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> res; // Initialize the result vector of vectors
       vector<int> tmpSet; // Temporary vector to hold subsets during recursion
       dfs(nums, res, 0, tmpSet); // Call the DFS function
       return res; // Return the final result
    }

    // DFS function to generate subsets
    void dfs(vector<int>& nums, vector<vector<int>>& res, int begin, vector<int>& tmpSet){
        res.push_back(tmpSet); // Add the current temporary subset to the result
        
        // Iterate through remaining elements in nums
        for(int i = begin; i < nums.size(); ++i){
            tmpSet.push_back(nums[i]); // Include current element in the temporary subset
            dfs(nums, res, i+1, tmpSet); // Recursively generate subsets with the current element
            tmpSet.pop_back(); // Backtrack by removing the last added element
        }
    }
};

