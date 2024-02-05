/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *     ListNode *next;
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
#if 0
        if(head == NULL){return false;}
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                return true;
            }
        }
        return false;
#endif
#if 1
    unordered_set<ListNode*> set;
    int cnt = 0;
    while(head != NULL){
        if(set.size() < cnt){
            return true;
        }else{
            cnt++;
            set.insert(head);
            head = head->next;
        }
    }
    return false;
#endif
#if 0
    unordered_map<ListNode*, int> dic;
    while(head != NULL){
        if(dic.count(head)){
            return true;
        }else{
            dic[head]++;
        }
        head = head->next;
    }
    return false;

#endif

        
    }
};