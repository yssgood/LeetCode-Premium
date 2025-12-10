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
    public ListNode plusOne(ListNode head) {
        ListNode newHead = null; 
        ListNode curr = head; 
        while(curr != null){
            ListNode tmp = curr.next; 
            curr.next = newHead; 
            newHead = curr; 
            curr = tmp; 
        }

        //3 -> 2 -> 1

        int carry = newHead.val + 1 >= 10 ? 1 : 0; 
        curr = newHead; 
        curr.val = (newHead.val + 1) % 10; 
        while(curr.next != null){
            int sum = (curr.next.val + carry) % 10; 
            carry = (curr.next.val + carry >= 10) ? 1 : 0; 
            curr.next.val = sum; 
            curr = curr.next; 
        }

        if(carry > 0) curr.next = new ListNode(carry); 

        curr = null; 
        while(newHead != null){
            ListNode tmp = newHead.next; 
            newHead.next = curr; 
            curr = newHead; 
            newHead = tmp; 
        }


        return curr; 
    }
}