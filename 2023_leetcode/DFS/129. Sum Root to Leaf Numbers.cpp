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
public:
    // Helper function for depth-first search (DFS) to calculate the sum of numbers formed by root-to-leaf paths
    int dfsRoofToLeafNum(TreeNode* root, int val) {
        if (root == nullptr) return 0; // If the node is NULL, return 0 (base case).

        val = val * 10 + root->val; // Update the value by appending the current node's value.

        if (root->left == nullptr && root->right == nullptr) {
            return val; // If the node is a leaf node, return the accumulated value (a complete number).
        }

        // Recursively calculate the sum of numbers formed by root-to-leaf paths in the left and right subtrees.
        return dfsRoofToLeafNum(root->right, val) + dfsRoofToLeafNum(root->left, val);
    }

    // Main function to find the sum of numbers formed by root-to-leaf paths in the binary tree
    int sumNumbers(TreeNode* root) {
        return dfsRoofToLeafNum(root, 0); // Start the DFS from the root with an initial value of 0.
    }
};
