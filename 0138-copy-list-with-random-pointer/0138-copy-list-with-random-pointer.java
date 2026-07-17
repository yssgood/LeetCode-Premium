class Solution {
    public Node copyRandomList(Node head) {
        Map<Integer, Node> hashMap = new HashMap<>();      // 인덱스 → 복사노드
        Map<Integer, Node> randomMap = new HashMap<>();    // 인덱스 → 원본random
        Map<Node, Integer> indexMap = new HashMap<>();     // 원본노드 → 인덱스 (추가!)

        Node curr = head;
        int index = 0;

        while (curr != null) {
            Node copy = new Node(curr.val);
            hashMap.put(index, copy);
            randomMap.put(index, curr.random);
            indexMap.put(curr, index);      // 원본 노드의 위치 기록
            index++;
            curr = curr.next;
        }

        Node dummy = new Node(-1);
        Node dummyCopy = dummy;

        for (int i = 0; i < index; i++) {
            Node next = null;
            Node currNode = hashMap.get(i);
            Node random = randomMap.get(i);

            if (hashMap.containsKey(i + 1)) {
                next = hashMap.get(i + 1);        // i → i+1 로 수정
            }

            if (random != null) {
                random = hashMap.get(indexMap.get(random));   // 새 노드 X, 대응 복사본
            }

            currNode.next = next;
            currNode.random = random;
            dummyCopy.next = currNode;
            dummyCopy = dummyCopy.next;
        }

        return dummy.next;
    }
}