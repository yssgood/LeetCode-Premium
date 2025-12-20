class Solution {
    public int shortestWay(String source, String target) {
        Set<Character> hashSet = new HashSet<>(); 
        for(char c : source.toCharArray()) hashSet.add(c); 

        int count = 0; 
        int start = 0, end = 0; 
        while(end < target.length()){
            if(!hashSet.contains(target.charAt(end))) return -1; 
            int startIndex = end; 
            while(start < source.length() && end < target.length()){
                if(source.charAt(start) == target.charAt(end)){
                    end++; 
                }
                start++; 
            }

            if(end == startIndex){
                return -1; 
            }

            start = 0; 
            count++; 
        }

        return count; 
    }
}