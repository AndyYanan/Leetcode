/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){ 
        int largeTar = max(p->val, q->val);
        int smallTar = min(p->val, q->val);
        while(root){
            if(largetTar < root->val){
                root = root->left;
            }
            else if(smallTar > root->val){
                root = root->right
            }else{
                return root;
            }
        }
    }
};