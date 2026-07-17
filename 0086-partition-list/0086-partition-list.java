/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode partition(ListNode head, int x) {
        ListNode smallDummy = new ListNode(-1); 
        ListNode bigDummy = new ListNode(-1); 
        
        ListNode smallCurr = smallDummy; 
        ListNode bigCurr = bigDummy; 

        while(head != null){
            int val = head.val; 
            if(val < x){
                smallCurr.next = new ListNode(val); 
                smallCurr = smallCurr.next; 
            } else{
                bigCurr.next = new ListNode(val); 
                bigCurr = bigCurr.next; 
            }
            head = head.next; 
        }

        smallCurr.next = bigDummy.next; 

        
        return smallDummy.next; 
    }
}