class Solution {
    public List<List<Integer>> kSmallestPairs(int[] nums1, int[] nums2, int k) {
        List<List<Integer>> answer = new ArrayList<>();
        
        // min-heap: [sum, index1, index2]
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        
        // start with first element of nums1 paired with nums2[0]
        for (int i = 0; i < Math.min(nums1.length, k); i++) {
            pq.offer(new int[]{nums1[i] + nums2[0], i, 0});
        }
        
        while (k-- > 0 && !pq.isEmpty()) {
            int[] curr = pq.poll();
            int i = curr[1];
            int j = curr[2];
            
            answer.add(Arrays.asList(nums1[i], nums2[j]));
            
            // expand right in nums2
            if (j + 1 < nums2.length) {
                pq.offer(new int[]{nums1[i] + nums2[j+1], i, j+1});
            }
        }
        
        return answer;
    }
}