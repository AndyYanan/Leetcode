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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res; // Initialize the result vector to store the rightmost node's values
        if(root == nullptr) return res; // If the tree is empty(root is NULL), return an empty result.
        queue<TreeNode*> q; // Create a queue to perform level-order traversal
        q.push(root);

        while(q.size()){ // Start the level order traversal loop until the queue is empty.
            int len = q.size(); // get the number of nodes in the current level
            int mostRight = 0; // Track of whether the current node is the rightmost in the level.

            // Traversal through all the nodes in the current level
            for(int i = 0; i < len; ++i){
                TreeNode* tmp = q.front(); // Get the front node from the queue.
                q.pop();
                if(mostRight == 0){ // Check if current node is the first node in the current level (rightmost node)
                    res.push_back(tmp->val); // add the value of the current node to the result vector
                    mostRight = 1;  // Mark that the rightmost node for this level has been found.
                }

                // Add the right and left children of the current node to the queue for the next level traversal
                if(tmp->right) q.push(tmp->right);
                if(tmp->left)  q.push(tmp->left);
            }
        }
        return res;
    }

public:
    void rightMostEachLevel(TreeNode* root, int depth, vector<int>& res){
        if(root == nullptr) return;

        int lenCurrLevel = res.size();
        if(lenCurrLevel == depth){
            res.push_back(root->val); // Add the rightmost node's value to the result vector
        }
        /*if(root->right)*/ rightMostEachLevel(root->right, depth + 1, res); // Recur to the right subtree
        /*if(root->left)*/  rightMostEachLevel(root->left, depth + 1, res);  // Recur to the left subtree
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res = {}; // Initialize the result vector to store the rightmost node's values.
        if(root == nullptr) return res;
        rightMostEachLevel(root, 0, res);
        return res;
    }


};