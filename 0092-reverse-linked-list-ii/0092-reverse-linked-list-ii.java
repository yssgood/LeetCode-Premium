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
    public ListNode reverseBetween(ListNode head, int left, int right) {
        ListNode dummy = new ListNode(-1); 
        dummy.next = head; 
        ListNode curr = dummy; 
        for(int i = 0; i < left - 1; i++){
            curr = curr.next; 
        }
        
        ListNode tail = curr.next; 
        ListNode newHead = curr.next; 
        ListNode prev = null; 
        for(int i = left; i <= right; i++){
            ListNode tmp = newHead.next; 
            newHead.next = prev; 
            prev = newHead; 
            newHead = tmp; 
        }

        curr.next = prev; 
        tail.next = newHead; 

        return dummy.next; 
    }
}