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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode *pre = &dummy;
        for(int i = 0; i < left-1; ++i){
            pre = pre->next;
        }
        ListNode *cur = pre->next;
        for(int j = 0; j < right-left; ++j){
            ListNode *nxt = cur->next;
            cur->next = nxt->next;
            nxt->next = pre->next;
            pre->next = nxt;
        }
        return dummy.next;

#if 0
        if(left==right)return head;
        ListNode dummy(0);
        ListNode *prev, *curr;
        ListNode *fir, *sec; 
        prev = nullptr, curr = head;
        for(int i = 0; i < left-1; ++i){
            prev = curr;
            curr = curr->next;
        }
        fir = prev, sec = curr;
        for(int j = left; j <= right; ++j){
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        sec->next = curr;
        if(fir){
            fir->next = prev;
        }
        return fir==nullptr?prev:head;
#endif
#if 0        
        ListNode dummy(0);
        dummy.next = head;
        ListNode *pre = &dummy;
        for(int i = 0; i < left-1; i++){
            pre = pre->next;
        }
        ListNode *pivot = pre->next;
        
        for(int i = left; i < right; i++){
            ListNode *next = pivot->next;
            pivot->next = next->next;
            next->next = pre->next;
            pre->next = next;
        }
        return dummy.next;
#endif    
    }
};           