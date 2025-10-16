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
    ListNode* partition(ListNode* head, int x) {
        ListNode* lessDummy = new ListNode(-1); 
        ListNode* greaterDummy = new ListNode(-1); 

        ListNode* less = lessDummy;
        ListNode* greater = greaterDummy; 

        ListNode* curr = head; 
        while(curr){
            if(curr->val < x){
                less->next = curr; 
                less = less->next; 
            } else{
                greater->next = curr; 
                greater = greater->next; 
            }
            curr = curr->next; 
        }

        greater->next = nullptr; 
        less->next = greaterDummy->next; 

        return lessDummy->next; 
    }
};