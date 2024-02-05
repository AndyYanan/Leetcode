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
    vector<vector<int>> res;
public:
    void buildVector(TreeNode* root, int depth){
        if(root == nullptr) return;
        if(res.size() == depth){
            res.push_back({});
        }
        res[depth].push_back(root->val);
        if(root->left) buildVector(root->left, depth+1);
        if(root->right) buildVector(root->right, depth+1);
    }
    vector<vector<int> > levelOrder(TreeNode *root) {
        buildVector(root, 0);
        return res;
    }
};
 #if 0
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        std::queue<TreeNode *> q;
        q.push(root);
        while(q.size()){
            int n = q.size();
            vector<int> level;
            for(int i=0; i<n; ++i){
                TreeNode* temp = q.front();
                level.push_back(temp->val);
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            res.push_back(level);
        }
        return res;
    }
};
#endif