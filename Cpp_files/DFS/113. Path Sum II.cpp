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
    vector<vector<int>> res;
    void dfs(TreeNode* root, int tar, vector<int>& nodePath){
        if(root == nullptr) return;
        nodePath.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr){
            if(root->val == tar){
                res.push_back(nodePath);
            }
        }
        if(root->left) {
            dfs(root->left, tar-root->val, nodePath);
        }    
        if(root->right){
            dfs(root->right, tar-root->val, nodePath);
        } 
        nodePath.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> nodePath;
        dfs(root, targetSum, nodePath);
        return res;
    }
};