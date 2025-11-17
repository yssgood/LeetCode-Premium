class Solution {
    public String alienOrder(String[] words) {

        // 등장한 문자만 관리
        Set<Character> chars = new HashSet<>();
        for (String s : words) {
            for (char c : s.toCharArray()) chars.add(c);
        }

        Map<Character, List<Character>> adj = new HashMap<>();
        Map<Character, Integer> inOrder = new HashMap<>();

        // 초기화
        for (char c : chars) {
            adj.put(c, new ArrayList<>());
            inOrder.put(c, 0);
        }

        // 간선 생성
        for (int i = 0; i < words.length - 1; i++) {
            String a = words[i];
            String b = words[i + 1];

            // prefix 반례
            if (a.startsWith(b) && a.length() > b.length()) return "";

            int min = Math.min(a.length(), b.length());

            for (int j = 0; j < min; j++) {
                if (a.charAt(j) != b.charAt(j)) {
                    char u = a.charAt(j);
                    char v = b.charAt(j);

                    adj.get(u).add(v);
                    inOrder.put(v, inOrder.get(v) + 1);
                    break;
                }
            }
        }

        // 위상정렬
        Queue<Character> q = new LinkedList<>();
        for (char c : chars) {
            if (inOrder.get(c) == 0) q.add(c);
        }

        StringBuilder sb = new StringBuilder();

        while (!q.isEmpty()) {
            char curr = q.poll();
            sb.append(curr);

            for (char next : adj.get(curr)) {
                inOrder.put(next, inOrder.get(next) - 1);
                if (inOrder.get(next) == 0) q.add(next);
            }
        }

        // 모든 노드를 다 방문하지 못하면 사이클
        if (sb.length() != inOrder.size()) return "";

        return sb.toString();
    }
}
