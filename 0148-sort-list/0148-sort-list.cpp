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
    ListNode* sortList(ListNode* head) {
        vector<int> tmp; 
        ListNode* dummy = new ListNode(-1); 
        ListNode* curr = dummy; 
        while(head){
            tmp.push_back(head->val); 
            head = head->next; 
        }
        sort(tmp.begin(),tmp.end()); 
        for(int n : tmp){
            curr->next = new ListNode(n); 
            curr = curr->next; 
        }
        return dummy->next; 
    }
};