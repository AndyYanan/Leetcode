/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
/*
    // Function to perform level-order traversal on a tree of nodes.
    vector<vector<int>> levelOrder(Node* root) {
        if(root == nullptr) return {}; // If the tree is empty (root is NULL), return an empty vector.

        queue<Node*> qNode; // Create a queue to store the nodes of each level for level-order traversal.
        qNode.push(root); // Push the root node into the queue as the starting point of traversal.
        vector<vector<int>> res; // Create a vector to store the values of each level.

        // Start the level-order traversal until the queue is empty.
        while(!qNode.empty()){
            int len = qNode.size(); // Get the number of nodes in the current level.
            vector<int> curLevelVal; // Vector to store the values of the nodes in the current level.

            // Traverse all the nodes in the current level.
            while(len--){
                Node* tmpNode = qNode.front(); // Get the front node from the queue.
                qNode.pop(); // Remove the processed node from the queue.

                curLevelVal.push_back(tmpNode->val); // Store the value of the current node.

                // Add all the children of the current node to the queue for the next level traversal.
                for(auto child: tmpNode->children){
                    qNode.push(child);
                }
            }
            res.push_back(curLevelVal); // Store the values of the current level in the result vector.
        }

        return res; // Return the vector containing the values of each level in the tree.
    }
*/

    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res; // Create a 2D vector to store the values of each level.
        dfs(root, 0, res); // Call the depth-first search (dfs) function to populate the 'res' vector.
        return res; // Return the vector containing the values of each level in the tree.
    }

    // Depth-first search (dfs) function to traverse the tree and populate the 'res' vector.
    void dfs(Node* root, int level, vector<vector<int>>& res) {
        if (root == nullptr) return; // If the node is NULL, simply return.

        if (res.size() == level) res.push_back({}); // If the current level is not yet represented in 'res', add an empty vector for it.

        res[level].push_back(root->val); // Store the value of the current node in the vector corresponding to its level.

        // Recursively call the dfs function for all the children of the current node.
        for (auto child : root->children) {
            dfs(child, level + 1, res);
        }
    }


};

