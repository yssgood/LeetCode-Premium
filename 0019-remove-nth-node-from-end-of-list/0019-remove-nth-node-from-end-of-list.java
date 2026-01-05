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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if(head == null) return head; 
        ListNode slow = head; 
        ListNode fast = head; 

        for(int i = 0; i < n; i++){
            fast = fast.next; 
        }

        //if(fast != null) System.out.print(fast.val); 

        if(fast == null) return head.next; 


        while(fast != null && fast.next != null){
            slow = slow.next; 
            fast = fast.next; 
        }

        // System.out.print(slow.val);  
        // if(fast != null) System.out.print(fast.val); 

        slow.next = slow.next.next; 
        return head; 

    }
}