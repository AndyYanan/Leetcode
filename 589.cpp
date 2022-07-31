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
    vector<int> preorder(Node* root) {
        vector<int> res;
        stack<int> tmp;
        if(root == nullptr) return res;
        tmp.push(root);
        while(!tmp.empty()){
            Node *cur = tmp.top();
            tmp.pop();
            res.push_back(cur->val);
            for(int i = cur->children.size()-1; i>=0; --i){
                tmp.push(cur->children[i]);
            }// push right Node first, pop left Node first
        }
        return res;

    }
};