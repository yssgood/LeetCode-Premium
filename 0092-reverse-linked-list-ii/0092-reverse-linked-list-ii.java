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
        for(int i = 1; i < left; i++){
            curr = curr.next; 
        }
        ListNode lastTail = curr.next; 
        ListNode newTail = curr.next; 
        ListNode newHead = null; 
        for(int i = left; i <= right; i++){
            ListNode tmp = newTail.next; 
            newTail.next = newHead; 
            newHead = newTail; 
            newTail = tmp; 
        }
        lastTail.next = newTail; 
        curr.next = newHead; 
        return dummy.next; 
    }
}