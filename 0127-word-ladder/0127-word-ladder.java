class Solution {
    public class Count{
        public String word; 
        public int count; 
        public Count(String word, int count){
            this.word = word;  
            this.count = count; 
        }
    }
    public boolean findDiff(String curr, String compare){
        int cnt = 0; 
        for(int i = 0; i < curr.length(); i++){
            if(curr.charAt(i) != compare.charAt(i)) cnt++; 
            if(cnt > 1) return false; 
        }
        return true; 
    }
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Map<String,Integer> hashMap = new HashMap<>(); 
        Queue<Count> queue = new LinkedList<>(); 
        for(String s : wordList){
            hashMap.put(s,0); 
        }
        if(!hashMap.containsKey(endWord)) return 0; 
        queue.add(new Count(beginWord,1)); 
        while(!queue.isEmpty()){
            int size = queue.size(); 
            for(int i = 0; i < size; i++){
                Count first = queue.poll(); 
                String curr = first.word; 
                int dist = first.count; 
                
                if(curr.equals(endWord)) return dist; 
                
                for(String ss : wordList){
                    if(hashMap.get(ss) != 1 && findDiff(curr,ss)){
                        hashMap.put(ss,1); 
                        queue.add(new Count(ss,dist+1)); 
                    }
                }
            }
        }
        return 0; 
    }
}