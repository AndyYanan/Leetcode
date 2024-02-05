class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        while(root){
            if(root->left){
                TreeNode *pre = root->left;
                while(pre->right && pre->right != root){
                    pre = pre->right;
                }
                if(pre->right){
                    pre->right = nullptr;
                    nodes.push_back(root->val);
                    root = root->right;
                }else{
                    pre->right = root;
                    root = root->left;
                }
            }else{
                nodes.push_back(root->val);
                root = root->right;
            }
        }
        return nodes;
    }
};