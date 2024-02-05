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
    // Stores the final results: a vector of vectors to hold each level's elements
    vector<vector<int>> res;
public:
    void bfs_level(TreeNode* root, int high){
        if(root == NULL) return res; // If the tree is empty (root is NULL), return an empty result.

        std::queue<TreeNode *> q; // Create a queue to perform level-order traversal.
        q.push(root); // Push the root node into the queue as the starting point of traversal.

        while(q.size()){ // Start the level-order traversal loop until the queue is empty.
            int n = q.size(); // Get the number of nodes in the current level.
            vector<int> level; // Create a vector to store the elements of the current level.

            for(int i=0; i<n; ++i){ // Traverse through all the nodes in the current level.
                TreeNode* temp = q.front(); // Get the front node from the queue.
                level.push_back(temp->val); // Add the value of the current node to the level vector.
                q.pop(); // Remove the processed node from the queue.

                // Add the left and right children of the current node to the queue for the next level traversal.
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }

            res.push_back(level); // Add the elements of the current level to the final result.
        }

        return res; 

       /*
        if(root == nullptr){
            return;
        }
        // If the current level's vector is not yet created
        // , add and empty vector for that level
        if(res.size() == high){
            res.push(vector<int>());
        }
        // Add the current node's value to the corresponding level's vector
        res[high].push_back(root->val);
        // Recursive traverse the left and right subtrees, increasing the depth for the next level
        if(root->left) bfs_level(root->left, high + 1);
        if(root->right) bfs_level(root->right, high + 1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {   
        bfs_level(root, 0);
    }
    */
};
