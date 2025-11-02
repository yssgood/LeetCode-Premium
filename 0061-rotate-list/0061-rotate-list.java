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
        if(head == null) return head; 
        ListNode newTail = head; 
        int size = 0; 
        while(newTail.next != null){
            size++; 
            newTail = newTail.next; 
        }
        size++; 
        //System.out.print(size); 
        k = k % size; 
        if(k == 0) return head; 
        ListNode curr = head; 
        for(int i = 0; i < size - k - 1; i++){
            curr = curr.next; 
        }

        System.out.print(curr.val); 

        ListNode newHead = curr.next; 
        curr.next = null; 
        newTail.next = head; 
        return newHead; 
    }
}