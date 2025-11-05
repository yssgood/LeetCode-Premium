class Solution {
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        PriorityQueue<Integer> pq = new PriorityQueue<>((a,b) -> {
            int diffA = Math.abs(a - x); 
            int diffB = Math.abs(b - x); 

            if(diffA == diffB){
                return b - a; 
            } else{
                return diffB - diffA; 
            }
        }); 
        // add all elements
        for (int num : arr) {
            pq.offer(num);
            
            // keep only k closest
            if (pq.size() > k) {
                pq.poll();  // remove farthest
            }
        }
        
        // build result and sort
        List<Integer> answer = new ArrayList<>();
        while (!pq.isEmpty()) {
            answer.add(pq.poll());
        }
        Collections.sort(answer);
        
        return answer;
    }
}