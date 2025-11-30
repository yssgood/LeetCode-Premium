class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode dummy = new ListNode(-1);
        //dummy.next = head; 

        ListNode prevGroupTail = dummy; 
        ListNode curr = head; 

        while (true) {
            // curr에서 시작해서 k번째 노드 찾기
            ListNode kth = getKth(curr, k);
            if (kth == null) break;           // k개 미만이면 종료

            ListNode groupNext = kth.next;    // 다음 그룹 시작점
            ListNode newHead = null;
            ListNode tail = curr;             // 현재 그룹의 head → 뒤집힌 후 tail

            // curr ~ kth 까지 뒤집기 (groupNext 전까지)
            while (curr != groupNext) {
                ListNode tmp = curr.next;
                curr.next = newHead;
                newHead = curr;
                curr = tmp;
            }

            // 이전 그룹의 tail → 이번 그룹의 새 head 연결
            prevGroupTail.next = newHead;

            // 이번 그룹의 tail → 다음 그룹 시작점 연결
            tail.next = groupNext;

            // 다음 루프 준비
            prevGroupTail = tail;
            curr = groupNext;
        }

        return dummy.next; 
    }

    // start에서 시작해서 k번째 노드를 반환 (k개 미만이면 null)
    private ListNode getKth(ListNode start, int k) {
        while (start != null && k > 1) {
            start = start.next;
            k--;
        }
        return start;
    }
}
