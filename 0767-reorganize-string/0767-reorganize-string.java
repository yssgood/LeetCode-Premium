class Solution {
    class Pair {
        int frequency; 
        char letter; 
        public Pair(int frequency, char letter){
            this.frequency = frequency;  
            this.letter = letter; 
        }
    }
    public String reorganizeString(String s) {
        if(s.length() == 1) return s; 
        StringBuilder answer = new StringBuilder(); 
        Map<Character,Integer> hashMap = new HashMap<>(); 
        for(char c : s.toCharArray()) hashMap.put(c, hashMap.getOrDefault(c,0) + 1); 
        PriorityQueue<Pair> pq = new PriorityQueue<>((a,b) -> b.frequency - a.frequency); 
        for(char c : hashMap.keySet()){
            pq.offer(new Pair(hashMap.get(c), c)); 
        }

        while(pq.size() > 1){
            Pair first = pq.poll(); 
            Pair second = pq.poll(); 

            answer.append(first.letter).append(second.letter); 
            first.frequency--; 
            second.frequency--;  

            if(first.frequency > 0){
                pq.offer(first); 
            }
            if(second.frequency > 0){
                pq.offer(second); 
            }
        }

        if(pq.isEmpty()) return answer.toString(); 
        if(!pq.isEmpty() && pq.peek().frequency > 1) return "";
        answer.append(pq.peek().letter); 
        return answer.toString();  
    }
}