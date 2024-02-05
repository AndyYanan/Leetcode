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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr) return true;
        if(p == nullptr || q == nullptr) return false;
        if(p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        /*queue<TreeNode*> queNode;
        queNode.push(p);
        queNode.push(q);
        while(!queNode.empty()){
            TreeNode* tmpp = queNode.front();
            queNode.pop(); 
            TreeNode* tmpq = queNode.front();
            queNode.pop();
            if(tmpp == nullptr && tmpq == nullptr) continue;
            if(tmpp == nullptr || tmpq == nullptr) return false;
            if(tmpp->val != tmpq->val) return false;
            queNode.push(tmpp->left);
            queNode.push(tmpq->left);
            queNode.push(tmpp->right);
            queNode.push(tmpq->right);
        }
        return true;*/
    }
};