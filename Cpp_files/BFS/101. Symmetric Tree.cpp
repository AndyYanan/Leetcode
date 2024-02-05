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
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        queue<TreeNode*> qleft, qright; // Create two queue for left and right subtrees
        qleft.push(root->left); // Push the left child of the root into the left queue
        qright.push(root->right); // Push the right child of the root into the right queue

        while(!qleft.empty() && !qright.empty()){ // Start the traversal loop until both queues are empty
            TreeNode* left = qleft.front(); // Get the front node from the left queue.
            qleft.top(); // Remove the processed node from the left queue
            TreeNode* right = qright.front(); // Get the front node from right queue
            qright.top();  // Remove the processed node from the right queue
            if(left == nullptr && right == nullptr) continue; // Both nodes are null, so continue to the nexe iteration
            if(left == nullptr || right == nullptr) return false; // One node is null while the other is not, so not symmetric
            if(left->val != right->val) return false; // check if the values of the nodes are different, not symmetric

            // Push the left child of left node and right child of right node to their respectuive queue
            qleft.push(left->left);
            qright.push(right->right);

            // Push the right child of left node and left child of right node to their respective queues
            qleft.push(left->right);
            qright.push(right->left);
        }
        return true; // If the loop finishes without returing false, the tree is symmetric
    }
};
 
/*
class Solution {
public:
    bool checkSymmetric(TreeNode* left, TreeNode* right){
        if(left == nullptr || right == nullptr){
            return left == right;
        }
        if(left->val != right->val){
            return false;
        }
        return checkSymmetric(left->left, right->right) && checkSymmetric(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        return root==nullptr || checkSymmetric(root->left, root->right);
    }
};
*/
*/