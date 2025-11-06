import java.util.*;

class Solution {
    public boolean possibleBipartition(int n, int[][] dislikes) {
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            adj.add(new ArrayList<>());
        }

        for (int[] g : dislikes) {
            adj.get(g[0]).add(g[1]);
            adj.get(g[1]).add(g[0]);
        }

        int[] colors = new int[n + 1]; // 0: uncolored, 1: group A, -1: group B

        for (int i = 1; i <= n; i++) {
            // If node not colored yet, start BFS to color its component
            if (colors[i] == 0) {
                Queue<Integer> q = new LinkedList<>();
                q.offer(i);
                colors[i] = 1; // Start with color 1

                while (!q.isEmpty()) {
                    int curr = q.poll();

                    for (int neighbor : adj.get(curr)) {
                        // If uncolored, color it opposite to current node
                        if (colors[neighbor] == 0) {
                            colors[neighbor] = -colors[curr];
                            q.offer(neighbor);
                        }
                        // If it already has the SAME color, we found a conflict
                        else if (colors[neighbor] == colors[curr]) {
                            return false;
                        }
                    }
                }
            }
        }

        return true; // No conflicts found in any component
    }
}