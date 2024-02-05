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
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return root;
        queue<TreeNode*> queNode;
        queNode.push(root);

        while(!queNode.empty()){
            TreeNode* tmpNode = queNode.front();
            queNode.pop();
            swap(tmpNode->left, tmpNode->right);
            if(tmpNode->left) queNode.push(tmpNode->left);
            if(tmpNode->right) queNode.push(tmpNode->right);
        }
        return root;
        /* 
        if(!root){
        }else{
            swap(root->left, tmp->right);
            invertTree(root->left);
            invertTree(root->right);   
        }
        
        return root;
        */
    }
};