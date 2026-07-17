/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        if(head == null) return null; 

        Map<Node,Node> hashMap = new HashMap<>(); 
        Node curr = head; 

        while(curr != null){
            hashMap.put(curr, new Node(curr.val)); 
            curr = curr.next; 
        }

        curr = head; 
        while(curr != null){
            hashMap.get(curr).next = hashMap.get(curr.next); 
            hashMap.get(curr).random = hashMap.get(curr.random); 
            curr = curr.next; 
        }

        return hashMap.get(head); 
    }
}