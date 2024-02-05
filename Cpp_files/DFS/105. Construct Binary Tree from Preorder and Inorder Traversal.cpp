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

// Solution class for constructing a binary tree from preorder and inorder traversals
//     3
//   /   \
//  9    20
//      /  \
//     15   7
class Solution {
public:
    // Helper function to construct a binary tree using preorder and inorder traversals
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int& preIdx, int left, int right) {
        if (left > right) return nullptr;
        int pivot = left;
        
        // Find the pivot index in the inorder traversal
        while (inorder[pivot] != preorder[preIdx]) {
            pivot++; // root value in the inorder tree
        }
         
        preIdx++; // next value of preorder tree as next root 
        TreeNode* newNode = new TreeNode(inorder[pivot]);
        
        // Recursively construct the left and right subtrees
        newNode->left = dfs(preorder, inorder, preIdx, left, pivot - 1);
        newNode->right = dfs(preorder, inorder, preIdx, pivot + 1, right);
        
        return newNode;
    }

    // Function to build a binary tree from preorder and inorder traversals
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len = preorder.size();
        int preIdx = 0;
        
        // Call the dfs function to construct the binary tree
        return dfs(preorder, inorder, preIdx, 0, len - 1);
    }
};
