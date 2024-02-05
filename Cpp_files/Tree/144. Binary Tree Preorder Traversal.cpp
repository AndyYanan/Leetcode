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
    void dfsPreorder(TreeNode* root, vector<int>& res){
        if(root == nullptr) return;
        res.push_back(root->val);
        dfsPreorder(root->left, res);
        dfsPreorder(root->right, res);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        dfsPreorder(root, res);
        return res;
    }
};

    vector<int> preorderTraversal(TreeNode* root) {
        if(root == nullptr) return{};

        vector<int> res;
        stack<TreeNode*> stkNode;
        stkNode.push(root);

        while(!stkNode.empty()){
            TreeNode* tmpNode = stkNode.top();
            stkNode.pop();
            res.push_back(tmpNode->val);
            if(tmpNode->right) stkNode.push(tmpNode->right);
            if(tmpNode->left) stkNode.push(tmpNode->left);
        }
        return res;

    }

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

vector<int> preorderTraversal(TreeNode* root) {
    if (root == nullptr) return {}; // If the root is null, return an empty vector.

    vector<int> res; // Vector to store the preorder traversal result.
    stack<TreeNode*> stkNode; // Stack to perform iterative preorder traversal.
    stkNode.push(root); // Push the root node into the stack.
    TreeNode* visitNode = root; // Pointer to keep track of the node being visited.

    while (!stkNode.empty()) { // While the stack is not empty, continue traversal.
        while (visitNode) { // Move down the left subtree until there are no more left children.
            res.push_back(visitNode->val); // Push the current node's value into the result vector.
            
            if (visitNode->right) { // If the current node has a right child, push it into the stack.
                stkNode.push(visitNode->right);
            }
            
            visitNode = visitNode->left; // Move to the left child for the next iteration.
        }

        visitNode = stkNode.top(); // Get the top node from the stack.
        stkNode.pop(); // Pop the node since we have traversed its left subtree.

        // Now, the next node to visit will be the right child of the last visited node.
    }

    return res; // Return the vector containing the preorder traversal result.
}

