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
    // Function to find the largest value in each level of the binary tree.
    vector<int> largestValues(TreeNode* root) {
        if(root == nullptr) return {}; // If the tree is empty (root is NULL), return an empty vector.

        queue<TreeNode*> qNode; // Create a queue to store the nodes of each level for level-order traversal.
        qNode.push(root); // Push the root node into the queue as the starting point of traversal.
        vector<int> res; // Create a vector to store the largest value in each level.
        int maxValue = INT_MIN; // Variable to store the maximum value in each level, initialized to the smallest possible integer.

        // Start the level-order traversal until the queue is empty.
        while(!qNode.empty()){
            int lenOfCurLevel = qNode.size(); // Get the number of nodes in the current level.
            maxValue = INT_MIN; // Reset the maxValue for each level.

            // Traverse all the nodes in the current level.
            for(int i = 0; i < lenOfCurLevel; i++){
                TreeNode* tmpNode = qNode.front(); // Get the front node from the queue.
                qNode.pop(); // Remove the processed node from the queue.

                maxValue = max(maxValue, tmpNode->val); // Update the maxValue with the maximum value in the current level.

                // Add the left and right children of the current node to the queue for the next level traversal.
                if(tmpNode->left) qNode.push(tmpNode->left);
                if(tmpNode->right) qNode.push(tmpNode->right);
            }

            res.push_back(maxValue); // Store the maximum value of the current level in the result vector.
        }

        return res; // Return the vector containing the largest value in each level of the binary tree.
    }
};

/*
class Solution {
public:
    void dfs(TreeNode* root, int level, vector<int> & res){
        if(root == nullptr) return;
        if(res.size() == level) res.push_back(root->val);
        else{
            if(res[level] < root->val){
                res[level] = root->val;
            }
        }
        dfs(root->left, level+1, res);
        dfs(root->right, level+1, res);
    }
    // Function to find the largest value in each level of the binary tree.
    vector<int> largestValues(TreeNode* root) {
        if(root == nullptr) return {};
        vector<int> res;
        dfs(root, 0, res);
        return res;
    }
};
*/