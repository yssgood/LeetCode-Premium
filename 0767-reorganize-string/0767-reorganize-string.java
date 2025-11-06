class Solution {
    public String reorganizeString(String s) {
        // Use Max-Heap to store [frequency, char_as_int]
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b) -> b[0] - a[0]);
        Map<Character, Integer> hashMap = new HashMap<>();
        for (char c : s.toCharArray()) hashMap.put(c, hashMap.getOrDefault(c, 0) + 1);
        for (char c : hashMap.keySet()) {
            pq.offer(new int[]{hashMap.get(c), (int)c}); // Cast char to int
        }

        StringBuilder sb = new StringBuilder();
        
        // Loop while we have at least 2 different characters to pair up
        while (pq.size() > 1) {
            int[] first = pq.poll();
            int[] second = pq.poll();

            // Append the characters back-to-back
            sb.append((char)first[1]);
            sb.append((char)second[1]);

            // Decrease frequency and add back to PQ if still needed
            if (--first[0] > 0) pq.offer(first);
            if (--second[0] > 0) pq.offer(second);
        }

        // If one character type is left
        if (!pq.isEmpty()) {
            int[] last = pq.poll();
            // If it has more than 1 instance left, it will conflict with itself. Impossible.
            if (last[0] > 1) return "";
            sb.append((char)last[1]);
        }

        return sb.toString();
    }
}