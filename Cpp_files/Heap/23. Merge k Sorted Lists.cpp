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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        ListNode dummy(0);
        ListNode *cur = &dummy;
        while(list1 && list2){
            if(list1->val > list2->val){
                cur->next = list2;
                list2 = list2->next;
            }else{
                cur->next = list1;
                list1 = list1->next;
            }
            cur = cur->next;
        }
        if(list1) cur->next = list1;
        else if(list2) cur->next = list2;
        return dummy.next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        ListNode *head = lists[0];
        for(int i = 1; i < lists.size(); i++){
            head = mergeTwoLists(head, lists[i]);
        }
        return head;
    }
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        ListNode dummy(0);
        ListNode *cur = &dummy;
        while(list1 && list2){
            if(list1->val > list2->val){
                cur->next = list2;
                list2 = list2->next;
            }else{
                cur->next = list1;
                list1 = list1->next;
            }
            cur = cur->next;
        }
        if(list1) cur->next = list1;
        else if(list2) cur->next = list2;
        return dummy.next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        ListNode *head = lists[0];
        for(int i = 1; i < lists.size(); i++){
            head = mergeTwoLists(head, lists[i]);
        }
        return head;

/*
struct compare {
    bool operator()(const ListNode* l, const ListNode* r) {
        return l->val > r->val;
    }
};
ListNode *mergeKLists(vector<ListNode *> &lists) { //priority_queue
    priority_queue<ListNode *, vector<ListNode *>, compare> q;
    for(auto l : lists) {
        if(l)  q.push(l);
    }
    if(q.empty())  return NULL;

    ListNode* result = q.top();
    q.pop();
    if(result->next) q.push(result->next);
    ListNode* tail = result;            
    while(!q.empty()) {
        tail->next = q.top();
        q.pop();
        tail = tail->next;
        if(tail->next) q.push(tail->next);
    }
    return result;
}

*/
    }
};