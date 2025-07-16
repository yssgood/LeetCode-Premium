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
    ListNode* reverseList(ListNode* head) {
        if(!head){
            return {}; 
        }

        if(!head->next){
            return head; 
        }

        ListNode* newTail = new ListNode(head->val); 
        ListNode* fastPointer;
        head = head->next; 
        while(head){
            fastPointer = new ListNode(head->val,newTail); 
            fastPointer->next = newTail; 
            head = head->next; 
            newTail = fastPointer; 
        }
        
        //cout << fastPointer->val; 

        // while(fastPointer){
        //     //cout << fastPointer->val << ' '; 
        //     fastPointer = fastPointer->next; 
        // }
        

        return fastPointer; 
    }
};