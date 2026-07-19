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
        if(lists.length <= 0) return null; 
        return mergeSort(lists, 0, lists.length-1); 
    }

    public ListNode mergeSort(ListNode[] lists, int left, int right){
        if(left == right){
            return lists[left]; 
        }

        int mid = left + (right - left) / 2; 
        ListNode leftNode = mergeSort(lists, left, mid); 
        ListNode rightNode = mergeSort(lists, mid + 1, right); 

        return merge(leftNode, rightNode); 
    }

    public ListNode merge(ListNode left, ListNode right){
        ListNode dummy = new ListNode(-1); 
        ListNode curr = dummy; 
        while(left != null && right != null){
            if(left.val <= right.val){
                curr.next = left; 
                left = left.next; 
            } else{
                curr.next = right; 
                right = right.next; 
            }
            curr = curr.next; 
        }

        if(left != null) curr.next = left; 
        if(right != null) curr.next = right;
        return dummy.next;
    }
}