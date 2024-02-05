/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;
        int len = 0;
        ListNode *cur = head;
        ListNode *pre = &dummy;
        while(cur){
            len++;
            cur = cur->next;
        }
        cur = head;
        while(len >= k){
            for(int i = 0; i < k-1; i++){
                ListNode *nxt = cur->next;
                cur->next = nxt->next; 
                nxt->next = pre->next; 
                pre->next = nxt;       
            }
            len -= k;
            pre = cur;
            cur = cur->next;
        }
        return dummy.next;

           /*     ListNode *pivot = head;
        for(int i = 0; i < k; ++i){
            if(pivot == nullptr){
                return head;
            }
            pivot = pivot->next;
        }
        ListNode* cur = head;
        ListNode* pre = nullptr;
        ListNode* nxt = nullptr;
        for(int i = 0; i < k; ++i){
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        head->next = reverseKGroup(cur, k);
        return pre;
*/
    }
}; 