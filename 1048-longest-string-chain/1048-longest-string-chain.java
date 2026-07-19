class Solution {
    public int longestStrChain(String[] words) {
        Arrays.sort(words, (a,b) -> Integer.compare(a.length(), b.length())); 
        Map<String,Integer> dp = new HashMap<>(); 
        int answer = 0; 

        for(String w : words){
            int best = 1; 
            for(int i = 0; i < w.length(); i++){
                String pred = w.substring(0,i) + w.substring(i+1); 
                if(dp.containsKey(pred)){
                    best = Math.max(best, dp.get(pred) + 1); 
                }
            }

            dp.put(w,best); 
            answer = Math.max(answer, dp.get(w)); 
        }

        return answer; 
    }
}