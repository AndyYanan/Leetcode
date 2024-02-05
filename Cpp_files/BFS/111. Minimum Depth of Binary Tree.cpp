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
    // Function to find the minimum depth of the binary tree.
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0; // If the tree is empty (root is NULL), the depth is 0.

        queue<TreeNode*> qNode; // Create a queue to perform level-order traversal.
        qNode.push(root); // Push the root node into the queue as the starting point of traversal.
        int resLen = 0; // Variable to store the minimum depth of the tree.

        // Start the level-order traversal until the queue is empty.
        while(!qNode.empty()){
            int lenofCurLevel = qNode.size(); // Get the number of nodes in the current level.
            resLen++; // Increment the depth, as we are now moving to the next level.

            // Traverse all the nodes in the current level.
            for(int i = 0; i < lenofCurLevel; ++i){
                TreeNode* tmpNode = qNode.front(); // Get the front node from the queue.
                qNode.pop(); // Remove the processed node from the queue.

                // If the current node is a leaf node (both left and right children are nullptr), return the depth.
                if(tmpNode->left == nullptr && tmpNode->right == nullptr) return resLen;

                // Add the left and right children of the current node to the queue for the next level traversal.
                if(tmpNode->left) qNode.push(tmpNode->left);
                if(tmpNode->right) qNode.push(tmpNode->right);
            }
        }

        return -1; // If the loop finishes without returning, it means the tree is empty, return -1.
    }
};
/*
class Solution {
public:
    // Function to find the minimum depth of the binary tree.
    int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0; // If the tree is empty (root is NULL), the depth is 0.
        }
        if(root->left == NULL && root->right == NULL){
            return 1; // If the current node is a leaf node (both left and right children are nullptr), return 1.
        }
        if(root->left == NULL){
            return minDepth(root->right) + 1; // If the left child is nullptr, return the depth of the right subtree + 1.
        }
        if(root->right == NULL){
            return minDepth(root->left)  + 1; // If the right child is nullptr, return the depth of the left subtree + 1.
        }

        // Return the minimum depth between the left and right subtrees + 1 (for the current node).
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};
*/
