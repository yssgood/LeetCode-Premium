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
    public ListNode reverseList(ListNode head) {
        if(head == null) return head; 
        ListNode newHead = null; 
        ListNode curr = head; 
        while(curr != null){
            ListNode tmp = curr.next; 
            curr.next = newHead; 
            newHead = curr; 
            curr = tmp; 
        }

        return newHead; 
    }
}