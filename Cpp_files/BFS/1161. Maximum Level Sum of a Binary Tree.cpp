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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> qNode;
        qNode.push(root);
        int maxLevel = INT_MIN;
        int res = 0, level = 0;
        while(!qNode.empty()){
            int len = qNode.size();
            int tmpSum = 0;
            level++;
            while(len--){
                TreeNode* tmpNode = qNode.front();
                qNode.pop();
                tmpSum += tmpNode->val;
                if(tmpNode->left) qNode.push(tmpNode->left);
                if(tmpNode->right) qNode.push(tmpNode->right);
            }
            if(tmpSum > maxLevel){
                maxLevel = tmpSum;
                res = level;
            }
        }      
        return res;
    }
};