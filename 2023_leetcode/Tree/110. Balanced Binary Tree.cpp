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

// Solution class for checking if a binary tree is balanced
class Solution {
public:
    // Helper function to calculate the depth of a binary tree
    int dfsDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        // Recursively calculate the depth of the left and right subtrees
        int leftHei = dfsDepth(root->left);
        int rightHei = dfsDepth(root->right);

        // If the left or right subtree is unbalanced or the height difference between them is greater than 1,
        // return -1 to indicate an unbalanced state.
        if (leftHei == -1 || rightHei == -1 || abs(leftHei - rightHei) > 1) {
            return -1;
        }

        // Return the height of the current node as the maximum height between its left and right subtrees + 1.
        // This ensures that the function returns the height of the subtree rooted at this node.
        return max(leftHei, rightHei) + 1;
    }

    // Function to check if a binary tree is balanced
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        
        // Call the depth function to check if the tree is balanced (depth difference <= 1)
        return dfsDepth(root) != -1;
    }
};
