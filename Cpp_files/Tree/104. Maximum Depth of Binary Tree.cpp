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
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;

        int resMaxDep = 0;
        queue<TreeNode*> q; // create the queue to perform level order traversal
        q.push(root); // push the root node into the queue as the starting point of traversal

        // Start to level-order traversal loop until the queue is empty
        while(!q.empty()){
            int lenOfCurLevel = q.size(); // Get the number of nodes in the current level
            resMaxDep++; // Increment the depth, as we are now moving to the next level
            for(int i = 0; i < lenOfCurLevel; i++){
                TreeNode* tmp = q.front(); // Get the front node from the queue
                q.pop();    // Remove the processed node from the queue

                // Add the left and right children of the current node to the queue for the next level traversal
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
        }
        return resMaxDep;

        /*
        if(root == nullptr) return 0;

        int leftMax = maxDepth(root->left);
        int rightMax = maxDepth(root->right);
        return max(rightMax, leftMax) + 1;
        */
    }
};