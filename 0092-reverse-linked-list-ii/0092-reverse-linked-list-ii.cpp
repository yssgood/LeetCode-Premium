class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || left == right) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        
        // Move to node before left
        for(int i = 1; i < left; i++) {
            prev = prev->next;
        }
        
        // Reverse the sublist
        ListNode* curr = prev->next;
        ListNode* next = nullptr;
        ListNode* reversedHead = nullptr;
        
        for(int i = left; i <= right; i++) {
            next = curr->next;
            curr->next = reversedHead;
            reversedHead = curr;
            curr = next;
        }
        
        // Connect back
        prev->next->next = curr;  // tail of reversed connects to rest
        prev->next = reversedHead;  // prev connects to new head
        
        return dummy->next;
    }
};