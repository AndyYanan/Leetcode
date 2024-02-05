/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// Solution class for finding the most frequent sum of subtrees in a binary tree
class Solution {
private:
    int maxcount; // variable to store the maximum frequency of a sum
    unordered_map<int, int> mp; // unordered_map to store the frequency of each sum

public:
    // Helper function to perform a depth-first search and calculate the sum of subtrees
    int dfs(TreeNode* root) {
        if (root == nullptr) return 0;
        int lsum = dfs(root->left);
        int rsum = dfs(root->right);
        int sum = lsum + rsum + root->val;
        maxcount = max(maxcount, ++mp[sum]); // update the maximum frequency and store the sum frequency
        return sum;
    }

    // Function to find the most frequent sum of subtrees in the binary tree
    vector<int> findFrequentTreeSum(TreeNode* root) {
        maxcount = 0;
        dfs(root); // find the sum frequencies and the maximum frequency
        vector<int> res;
        for (auto& ele : mp) {
            if (ele.second == maxcount) { // find all sums with the maximum frequency
                res.push_back(ele.first);
            }
        }
        return res;
    }
};
