class Solution {
    class Pair{
        String s;
        int count; 
        public Pair(String s, int count){
            this.s = s; 
            this.count = count; 
        }
    }
    public int openLock(String[] deadends, String target) {
        Set<String> hashSet = new HashSet<>();
        for(String s : deadends) hashSet.add(s); 
        Queue<Pair> q = new LinkedList<>(); 
        HashMap<String,Integer> hashMap = new HashMap<>(); 
        hashMap.put("0000",0); 
        q.offer(new Pair("0000",0)); 
        int answer = Integer.MAX_VALUE; 
        if(hashSet.contains("0000")) return -1; 
        while(!q.isEmpty()){
            int size = q.size(); 
            for(int i = 0; i < size; i++){
                Pair currPair = q.poll(); 
                String curr = currPair.s; 
                int count = currPair.count; 

                if(curr.equals(target)){
                    return count; 
                }

                //StringBuilder sb = new StringBuilder(curr); 
                for(int j = 0; j < target.length(); j++){
                    StringBuilder sb = new StringBuilder(curr); 
                    char c = sb.charAt(j); 
                    sb.setCharAt(j, (char)((c - '0' + 1) % 10 + '0'));
                    String next = sb.toString(); 
                    if(!hashSet.contains(next) && !hashMap.containsKey(next)){
                        q.offer(new Pair(next, count + 1)); 
                        hashMap.put(next,0); 
                    }
                    

                    // 감소시키기
                    sb.setCharAt(j, (char) ((c - '0' + 9) % 10 + '0'));  // 감소시키기 위해 +9
                    next = sb.toString();
                    if (!hashSet.contains(next) && !hashMap.containsKey(next)) {
                        q.offer(new Pair(next, count + 1));
                        hashMap.put(next,0);
                    }

                }
            }
        }
        return -1; 
    }
}