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
    void dfsPostorder(TreeNode* root, vector<int>& res){
        if(root == nullptr) return;
        dfsPostorder(root->left, res);
        dfsPostorder(root->right, res);
        res.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        dfsPostorder(root, res);
        return res;
    }

        vector<int> postorderTraversal(TreeNode* root) {
        if(root == nullptr) return {};
        vector<int> res;
        stack<TreeNode*> stkNode;
        stkNode.push(root);

        while(!stkNode.empty()){
            TreeNode* visitNode = stkNode.top();
            if(visitNode->left){
                stkNode.push(visitNode->left);
                visitNode->left = NULL;
            }else{
                if(visitNode->right){
                    stkNode.push(visitNode->right);
                    visitNode->right = NULL;
                }else{
                    res.push_back(visitNode->val);
                    stkNode.pop();
                }
            }
        }
        return res;
    }

};