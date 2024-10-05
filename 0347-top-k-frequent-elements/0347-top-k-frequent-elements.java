class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        HashMap<Integer,Integer> hashMap = new HashMap<>(); 
        for(int i = 0; i < nums.length; i++){
            hashMap.put(nums[i], hashMap.getOrDefault(nums[i],0) + 1); 
        }

        PriorityQueue<Integer> pq = new PriorityQueue<>((a,b)->{
            return hashMap.get(b) - hashMap.get(a); 
        });

        for(Integer n : hashMap.keySet()){
            pq.offer(n); 
        }

        List<Integer> answer = new ArrayList<>(); 
        while(k > 0){
            answer.add(pq.poll()); 
            k--; 
        }

        return answer.stream().mapToInt(Integer::intValue).toArray(); 
    }
}