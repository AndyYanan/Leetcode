class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // Sort the input array to handle duplicates
        vector<vector<int>> res;        // Resultant vector to store subsets
        vector<int> tmpVec;             // Temporary vector to store subsets during DFS
        dfs(nums, 0, res, tmpVec);       // Start DFS from index 0
        return res;                     // Return the final list of subsets
    }

    void dfs(vector<int>& nums, int begin, vector<vector<int>>& res, vector<int>& tmpVec){
        res.push_back(tmpVec);  // Include the current subset in the result
        for(int i = begin; i < nums.size(); ++i){
            if(i == begin || nums[i] != nums[i-1]){
                tmpVec.push_back(nums[i]);         // Include current element in the subset
                dfs(nums, i+1, res, tmpVec);       // Recursive call to explore subsets with this element
                tmpVec.pop_back();                // Backtrack by removing the current element
            }
        }
    }
};

Time Complexity: O(N * 2^N)
Space Complexity: O(2^N)




