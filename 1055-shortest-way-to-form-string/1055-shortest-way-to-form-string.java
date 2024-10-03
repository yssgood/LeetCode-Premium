class Solution {
    public int shortestWay(String source, String target) {
        int answer = 0; 
        int start = 0, end = 0; 
        HashMap<Character,Integer> hashMap = new HashMap<>(); 
        for(int i = 0; i  < source.length(); i++) hashMap.put(source.charAt(i),1); 
        while(end < target.length()){
            if(!hashMap.containsKey(target.charAt(end))) return -1; 
            while(start < source.length() && end < target.length()){
                if(target.charAt(end) == source.charAt(start)){
                    start++;
                    end++; 
                } else{
                    start++; 
                }
            }
            start = 0; 
            answer++; 
        }

        return answer; 
    }
}