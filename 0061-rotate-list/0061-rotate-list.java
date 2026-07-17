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
    public ListNode rotateRight(ListNode head, int k) {
        if(head == null) return null; 
        int size = 1; 
        ListNode curr = head; 
        while(curr.next != null){
            size++;
            curr = curr.next; 
        }

        k %= size; 
        if(k == 0) return head; 
        
        ListNode newTail = head; 
        for(int i = 0; i < size - k - 1; i++){
            newTail = newTail.next; 
        }

        ListNode newHead = newTail.next; 
        newTail.next = null; 
        curr.next = head; 

        return newHead; 
    }
}