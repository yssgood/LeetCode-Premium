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
    public ListNode deleteDuplicates(ListNode head) {
        ListNode dummy = new ListNode(-1); 
        ListNode curr = dummy; 
        while(head != null){
            boolean flag = false; 
            while(head.next != null && head.next.val == head.val){
                flag = true; 
                head = head.next; 
            }

            if(!flag){
                curr.next = new ListNode(head.val); 
                curr = curr.next; 
            } 
            head = head.next; 
        }
        return dummy.next; 
    }
}