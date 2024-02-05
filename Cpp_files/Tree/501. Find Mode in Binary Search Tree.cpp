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
    // time O(N), space O(1)
    vector<int> findMode(TreeNode* root) {
        // BST -> inorder traversal
        //unordered_map<int, int> counts; // key: node value, val: freq
        vector<int> res;
        int max_count = INT_MIN, val = INT_MIN, count = 0;
        inorder(root, res, max_count, val, count);
        return res; 
    }

    void inorder(TreeNode* root, vector<int>& res, int& max_count, int& val, int& count){
        if(root == NULL) return;
        inorder(root->left, res, max_count, val, count);
        countFreq(root, res, max_count, val, count);
        inorder(root->right, res, max_count, val, count);
    }
    void countFreq(TreeNode* root, vector<int>& res, int& max_count, int& val, int& count){
        if(root->val == val){
            count++;
        }else{
            count = 1;
            val = root->val;
        }
        if(count > max_count){
            res = {root->val};
            max_count = count;
        }else if(count == max_count){
            res.push_back(root->val);
        }
        return;
    }
/* O(N), O(N)
    vector<int> findMode(TreeNode* root) {
        // BST -> inorder traversal
        unordered_map<int, int> counts; // key: node value, val: freq
        vector<int> res;
        int max_count = 0;
        inorder(root, counts, res, max_count);
        return res; 
    }

    void inorder(TreeNode* root, unordered_map<int, int>& counts, vector<int>& res, int& max_count){
        if(root == NULL) return;
        inorder(root->left, counts, res, max_count);
        countFreq(root, counts, res, max_count);
        inorder(root->right, counts, res, max_count);
    }
    void countFreq(TreeNode* root, unordered_map<int, int>& counts, vector<int>& res, int& max_count){
        int count = ++counts[root->val];
        if(count > max_count){
            res = {root->val};
            max_count = count;
        }else if(count == max_count){
            res.push_back(root->val);
        }
        return;
    }
*/
};