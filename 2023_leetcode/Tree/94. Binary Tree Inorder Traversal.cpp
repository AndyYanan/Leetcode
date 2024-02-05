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
    void dfsInorder(TreeNode* root, vector<int>& res){
        if(root == nullptr) return;
        dfsInorder(root->left, res);
        res.push_back(root->val);
        dfsInorder(root->right, res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        dfsInorder(root, res);
        return res;
    }
};
/*
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr) return{};

        vector<int> res;
        stack<TreeNode*> stkNode;
        TreeNode* visitNode = root;
        while(visitNode != nullptr || !stkNode.empty()){
            while(visitNode != nullptr){
                stkNode.push(visitNode);
                visitNode = visitNode->left;
            }
            visitNode = stkNode.top();
            stkNode.pop();
            res.push_back(visitNode->val);
            visitNode = visitNode->right;
        }   
        return res;
    }
};
*/