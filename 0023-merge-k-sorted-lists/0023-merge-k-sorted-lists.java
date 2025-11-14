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
        if(lists.length == 0) return null; 
        return mergeList(lists, 0, lists.length-1); 
    }
    private ListNode mergeList(ListNode[] lists, int left, int right){
        if(left == right){
            return lists[left];
        }

        int mid = left + (right - left) / 2; 
        ListNode l1 = mergeList(lists, left, mid); 
        ListNode l2 = mergeList(lists, mid + 1, right); 


        return merge(l1,l2); 
    }

    private ListNode merge(ListNode l1, ListNode l2){
        ListNode dummy = new ListNode(-1); 
        ListNode curr = dummy; 

        while(l1 != null && l2 != null){
            if(l1.val < l2.val){
                curr.next = l1; 
                l1 = l1.next; 
            } else{
                curr.next = l2; 
                l2 = l2.next; 
            }
            curr = curr.next;
        }

        curr.next = (l1 != null) ? l1 : l2; 
        return dummy.next; 
    }
}