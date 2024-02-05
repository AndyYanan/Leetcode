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
    bool bfs(TreeNode* root, long left, long right){
        if(root == nullptr) return true;
        if(root->val <= left || root->val >= right){
            return false;
        }
        return bfs(root->left, left, root->val) && bfs(root->right, root->val, right);
    }
    bool isValidBST(TreeNode* root) {
        return bfs(root, LONG_MIN, LONG_MAX);
    }




    // Function to check if a binary tree is a valid binary search tree (BST)
    /*
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stkNode;
        TreeNode* visitNode = root;
        long pre = LONG_MIN; // To keep track of the previously visited node's value

        while (visitNode != nullptr || !stkNode.empty()) {
            while (visitNode != nullptr) {
                stkNode.push(visitNode);
                visitNode = visitNode->left;
            }
            visitNode = stkNode.top();
            stkNode.pop();

            // Check if the current node's value violates the BST property
            if (visitNode->val <= pre) {
                return false;
            }

            pre = visitNode->val; // Update the previously visited node's value
            visitNode = visitNode->right;
        }

        return true;
    }*/
};