class Solution {
    public int[] arrayRankTransform(int[] arr) {
        if(arr.length == 0) return arr; 
        PriorityQueue<Integer> pq = new PriorityQueue<>(); 
        Map<Integer,Integer> hashMap = new HashMap<>(); 

        for(int n : arr) pq.offer(n); 

        int rank = 1; 
        int lastNum = pq.peek(); 

        while(!pq.isEmpty()){
            int curr = pq.poll(); 
            if(curr != lastNum){
                rank++; 
                lastNum = curr; 
            }
            hashMap.put(curr,rank); 
        }

        int[] answer = new int[arr.length]; 
        for(int i = 0; i < arr.length; i++){
            answer[i] = hashMap.get(arr[i]); 
        }

        return answer; 
    }
}