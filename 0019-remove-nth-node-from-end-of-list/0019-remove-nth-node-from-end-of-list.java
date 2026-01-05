/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = dnext; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode slow = head; 
        ListNode fast = head; 
        while(fast != null && n > 0){
            fast = fast.next; 
            n--; 
        }

        while(fast != null && fast.next != null){
            slow = slow.next; 
            fast = fast.next; 
        }

        if(slow == fast) return null; 
        if(fast == null) return head.next; 
        slow.next = slow.next.next; 

        return head; 
    }
}

//[1,2]
//1 -> 2 -> null 
//2 