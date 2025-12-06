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
    public int pairSum(ListNode head) {
        ListNode slow = head; 
        ListNode fast = head.next.next; 
        
        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }

        ListNode curr = slow.next; 
        ListNode newHead = null; 
        while(curr != null){
            ListNode tmp = curr.next; 
            curr.next = newHead;
            newHead = curr; 
            curr = tmp; 
        }

        int maxSum = 0; 

        while(newHead != null && head != null){
            maxSum = Math.max(maxSum, newHead.val + head.val); 
            newHead = newHead.next; 
            head = head.next; 
        }

        

        return maxSum; 
    }
}