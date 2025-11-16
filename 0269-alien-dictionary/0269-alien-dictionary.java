class Solution {
    public String alienOrder(String[] words) {
        // Step 1: Build graph
        Map<Character, Set<Character>> graph = new HashMap<>();
        Map<Character, Integer> indegree = new HashMap<>();

        for (String word : words) {
            for (char c : word.toCharArray()) {
                indegree.putIfAbsent(c, 0);
                graph.putIfAbsent(c, new HashSet<>());
            }
        }

        // Step 2: Add edges from adjacent word pairs
        for (int i = 0; i < words.length - 1; i++) {
            String w1 = words[i];
            String w2 = words[i + 1];

            // invalid case: ["abc", "ab"]
            if (w1.startsWith(w2) && w1.length() > w2.length()) {
                return "";
            }

            int len = Math.min(w1.length(), w2.length());
            for (int j = 0; j < len; j++) {
                char c1 = w1.charAt(j);
                char c2 = w2.charAt(j);
                if (c1 != c2) {
                    if (graph.get(c1).add(c2)) { // new edge
                        indegree.put(c2, indegree.get(c2) + 1);
                    }
                    break;
                }
            }
        }

        // Step 3: BFS Topological Sort
        Queue<Character> q = new LinkedList<>();
        for (char c : indegree.keySet()) {
            if (indegree.get(c) == 0) q.add(c);
        }

        if(q.isEmpty()) return ""; 

        StringBuilder sb = new StringBuilder();

        while (!q.isEmpty()) {
            char curr = q.poll();
            sb.append(curr);

            for (char next : graph.get(curr)) {
                indegree.put(next, indegree.get(next) - 1);
                if (indegree.get(next) == 0) q.add(next);
            }
        }

        if (sb.length() != indegree.size()) return ""; // cycle
        return sb.toString();
    }
}
