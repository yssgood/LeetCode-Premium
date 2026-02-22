class Solution {
    class Pair {
        char letter;
        int frequency;
        public Pair(char letter, int frequency) {
            this.letter = letter;
            this.frequency = frequency;
        }
    }

    public String rearrangeString(String s, int k) {
        if (k <= 1) return s;

        Map<Character, Integer> hashMap = new HashMap<>();
        for (char c : s.toCharArray()) hashMap.put(c, hashMap.getOrDefault(c, 0) + 1);

        PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> b.frequency - a.frequency);
        for (Map.Entry<Character, Integer> entry : hashMap.entrySet()) {
            pq.add(new Pair(entry.getKey(), entry.getValue()));
        }

        Queue<Pair> q = new LinkedList<>();  // k턴 동안 대기
        StringBuilder sb = new StringBuilder();

        while (!pq.isEmpty()) {
            Pair first = pq.poll();        // 가장 빈도 높은 문자 꺼냄
            sb.append(first.letter);
            first.frequency--;

            q.add(first);                  // 대기열에 넣음 (빈도 0이어도 일단 넣음)

            if (q.size() >= k) {           // k턴 지났으면 복귀
                Pair back = q.poll();
                if (back.frequency > 0) pq.add(back);
            }
        }

        return sb.length() == s.length() ? sb.toString() : "";
    }
}