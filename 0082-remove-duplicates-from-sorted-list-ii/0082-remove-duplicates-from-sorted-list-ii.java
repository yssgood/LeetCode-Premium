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
        Map<Integer,Integer> hashMap = new HashMap<>(); 
        ListNode curr = head; 
        while(curr != null){
            hashMap.put(curr.val, hashMap.getOrDefault(curr.val,0) + 1); 
            curr = curr.next; 
        }

        ListNode dummy = new ListNode(-1); 
        ListNode newCurr = dummy; 
        curr = head; 

        while(curr != null){
            if(hashMap.get(curr.val) == 1){
                newCurr.next = new ListNode(curr.val); 
                newCurr = newCurr.next; 
            }
            curr = curr.next; 
        }

        return dummy.next; 
    }
}