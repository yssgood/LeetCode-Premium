class Solution {
    public String reorganizeString(String s) {
        HashMap<Character,Integer> hashMap = new HashMap<>(); 
        PriorityQueue<Character> pq = new PriorityQueue<>((a,b) -> {
            return hashMap.get(b) - hashMap.get(a); 
        });

        for(char c : s.toCharArray()){
            hashMap.put(c, hashMap.getOrDefault(c,0) + 1); 
        }

        for(Character c : hashMap.keySet()){
            pq.offer(c); 
        }

        StringBuilder sb = new StringBuilder(); 

        while(pq.size() > 1){
            Character first = pq.poll();
            Character second = pq.poll(); 
            sb.append(first).append(second); 

            hashMap.put(first, hashMap.get(first)-1); 
            hashMap.put(second, hashMap.get(second)-1); 

            if(hashMap.get(first) > 0) pq.offer(first);
            if(hashMap.get(second) > 0) pq.offer(second); 
        }

        while(!pq.isEmpty()){
            Character remain = pq.poll(); 
            if(hashMap.get(remain) > 1) return ""; 
            sb.append(remain); 
        }

        //System.out.print(sb.toString()); 

        
        return sb.toString(); 
    }
}