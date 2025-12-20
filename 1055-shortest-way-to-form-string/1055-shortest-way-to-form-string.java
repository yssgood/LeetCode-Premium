class Solution {
    public int shortestWay(String source, String target) {
        int count = 0; 
        int start = 0, end = 0; 
        Set<Character> hashSet = new HashSet<>(); 
        for(char c : source.toCharArray()) hashSet.add(c); 
        while(end < target.length()){
            
            while(end < target.length() && start < source.length()){
                if(source.charAt(start) == target.charAt(end)){
                    start++; 
                    end++; 
                } else{
                    if(!hashSet.contains(target.charAt(end))) return -1; 
                    start++; 
                }
            }


            if(start >= source.length()){
                start = 0; 
                end--; 
            }
            count++; 
            end++; 
        }

        return count; 
    }
}