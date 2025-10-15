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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* curr = head;
        int size = 0; 
        while(curr){
            size++; 
            curr = curr->next; 
        }

        int target = size - n; 
        if(target == 0) return head->next; 
        curr = head;
        while(curr){
            target--; 
            if(target == 0){
                curr->next = curr->next->next; 
                return head; 
            }
            curr = curr->next; 
        }
        return curr; 
    }
};