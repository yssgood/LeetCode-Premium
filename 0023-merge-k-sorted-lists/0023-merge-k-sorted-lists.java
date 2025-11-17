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
        if(lists == null) return null; 
        ListNode dummy = new ListNode(-1); 
        ListNode curr = dummy; 
        PriorityQueue<ListNode> pq = new PriorityQueue<>((a,b) -> a.val - b.val); 
        for(ListNode nodes : lists){
            if(nodes != null) pq.offer(nodes); 
        }
        while(!pq.isEmpty()){
            ListNode node = pq.poll();
            curr.next = new ListNode(node.val); 
            if(node.next != null){
                pq.offer(node.next); 
            }
            curr = curr.next; 
        }
        return dummy.next; 
    }
}