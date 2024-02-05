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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pivot = 0;
        int left = 0, right = preorder.size()-1;
        unordered_map<int, int> inHash;
        for(int i = 0; i < inorder.size(); i++){
            inHash[inorder[i]] = i;
        }
        return dfs(preorder, inorder, pivot, left, right, inHash);
    }
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int& pivot, int left, int right, unordered_map<int, int>& inHash){
        if(left > right) return nullptr;
        int inorderIdx = inHash[preorder[pivot]];

        pivot++;
        TreeNode* resNode = new TreeNode(inorder[inorderIdx]);
        resNode->left = dfs(preorder, inorder, pivot, left, inorderIdx-1, inHash);
        resNode->right = dfs(preorder, inorder, pivot, inorderIdx+1, right, inHash);
        return resNode;
    }
};

 