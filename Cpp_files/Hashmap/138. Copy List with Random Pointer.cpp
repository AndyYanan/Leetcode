/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Create an unordered map to store the mapping between original nodes and their corresponding copies
        unordered_map<Node*, Node*> mp;
        
        // Step 1: Create copies of each node and store them in the map, without linking next and random pointers
        Node* tmp = head;
        while (tmp) {
            // Create a new node with the same value as the original node
            mp[tmp] = new Node(tmp->val);
            tmp = tmp->next;
        } 
        
        // Step 2: Link the next and random pointers of the copied nodes using the information from the map
        tmp = head;
        while (tmp) {
            // Use the map to access the copied node corresponding to the current original node
            // and set its next and random pointers accordingly
            mp[tmp]->next = mp[tmp->next];
            mp[tmp]->random = mp[tmp->random];
            tmp = tmp->next;
        }
        
        // Return the head of the copied linked list
        return mp[head];
    }
};
