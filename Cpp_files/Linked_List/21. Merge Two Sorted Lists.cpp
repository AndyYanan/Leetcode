class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* resHead = &dummy;
        while(list1 && list2){
            if(list1->val >= list2->val){
                resHead->next = list2;
                list2 = list2->next;
            }else{
                resHead->next = list1;
                list1 = list1->next;
            }
            resHead = resHead->next;
        }
        if(list1){
            resHead->next = list1;
        }else if(list2){
            resHead->next = list2;
        }
        return dummy.next;
    }
}; 
