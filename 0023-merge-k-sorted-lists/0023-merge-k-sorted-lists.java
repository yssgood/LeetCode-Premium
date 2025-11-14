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
    public ListNode mergeKLists(ListNode[] lists) {
        if(lists.length < 1) return null; 
        ListNode dummy = new ListNode(-1); 
        ListNode curr = dummy; 
        PriorityQueue<ListNode> pq = new PriorityQueue<>((a,b) -> a.val - b.val); 
        
        for(ListNode lst : lists){
            if(lst == null) continue; 
            pq.offer(lst); 
        }

        while(!pq.isEmpty()){
            ListNode first = pq.poll(); 
            
            curr.next = new ListNode(first.val); 
            if(first.next != null){
                first = first.next; 
                pq.offer(first); 
            }
            curr = curr.next; 
        }

        return dummy.next; 

    }
}