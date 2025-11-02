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
        ListNode headDummy = new ListNode(-1); 
        ListNode tailDummy = new ListNode(-1); 
        ListNode headCurr = headDummy; 
        ListNode tailCurr = tailDummy; 
        while(head != null){
            if(head.val < x){
                headCurr.next = new ListNode(head.val); 
                headCurr = headCurr.next; 
            } else{
                tailCurr.next = new ListNode(head.val); 
                tailCurr = tailCurr.next; 
            }
            head = head.next; 
        }

        headCurr.next = tailDummy.next; 
        return headDummy.next; 
    }
}