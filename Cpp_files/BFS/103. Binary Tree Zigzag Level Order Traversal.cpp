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
    // Function to perform zigzag level order traversal of a binary tree.
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr) return {}; // If the tree is empty (root is NULL), return an empty result.

        queue<TreeNode*> q; // Create a queue to store the nodes of each level.
        q.push(root); // Push the root to the queue as the starting point of level order traversal.
        vector<vector<int>> res; // Result vector to store the traversal.

        int direction = 0; // Variable to keep track of the direction of traversal (0 - left to right, 1 - right to left).
        int lenOfCurLevel = 0; // Variable to store the number of nodes in the current level.

        // Start the level order traversal until the queue is empty.
        while(!q.empty()){
            lenOfCurLevel = q.size(); // Get the number of nodes in the current level.
            vector<int> resCurLevel(lenOfCurLevel); // Vector to store the elements of the current level.

            // Traverse all the nodes in the current level.
            for(int i = 0; i < lenOfCurLevel; ++i){
                TreeNode* tmpNode = q.front(); // Get the front node from the queue.
                q.pop(); // Remove the processed node from the queue.

                if(direction == 0){
                    resCurLevel[i] = tmpNode->val; // If direction is 0, store the value from left to right.
                }else{
                    resCurLevel[lenOfCurLevel - 1 - i] = tmpNode->val; // If direction is 1, store the value from right to left.
                }

                // Add the left and right children of the current node to the queue for the next level traversal.
                if(tmpNode->left)  q.push(tmpNode->left);
                if(tmpNode->right) q.push(tmpNode->right);
            }

            direction ^= 1; // Toggle the direction for the next level.
            res.push_back(resCurLevel); // Add the elements of the current level to the result.
        }

        return res; // Return the result vector containing zigzag level order traversal.
    }
};
