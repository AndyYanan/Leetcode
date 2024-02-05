class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        
        // Find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Split the list into two halves
        ListNode* secondHalf = slow->next;
        slow->next = nullptr; // Terminate the first half
        
        // Reverse the second half
        ListNode* prev = nullptr;
        while (secondHalf) {
            ListNode* temp = secondHalf->next;
            secondHalf->next = prev;
            prev = secondHalf;
            secondHalf = temp;
        }
        
        // Merge the two halves alternatively
        ListNode* firstHalf = head;
        while (prev) {
            ListNode* temp1 = firstHalf->next;
            ListNode* temp2 = prev->next;
            firstHalf->next = prev;
            prev->next = temp1;
            firstHalf = temp1;
            prev = temp2;
        }
    }
};
