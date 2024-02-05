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
class Solution {
private:
    int maxValue; // Private variable to store the maximum path sum
    
public:
    // Helper function to perform depth-first search (DFS) on the binary tree
    int dfs(TreeNode* root){
        if (root == NULL){
            return 0; // If the node is NULL, return 0.
        }
        
        // Recursively calculate the maximum path sum for the left and right subtrees
        int left = max(dfs(root->left), 0); // The maximum sum path in the left subtree
        int right = max(dfs(root->right), 0); // The maximum sum path in the right subtree
        
        // Calculate the potential maximum path sum that includes the current node (root)
        maxValue = max(maxValue, left + right + root->val);
        
        // Return the maximum path sum that can be extended to the parent node
        return max(left, right) + root->val;
    }
    
    // Main function to find the maximum path sum in the binary tree
    int maxPathSum(TreeNode* root) {
        maxValue = INT_MIN; // Initialize the maxValue to a very small value to handle negative node values.
        dfs(root); // Perform the depth-first search to calculate the maximum path sum.
        return maxValue; // Return the maximum path sum found in the binary tree.
    }
};
