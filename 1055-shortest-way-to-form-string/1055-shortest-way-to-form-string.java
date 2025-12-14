class Solution {
    public int shortestWay(String source, String target) {
        int sourceIndex = 0; 
        int targetIndex = 0; 
        int m = source.length(); 
        int n = target.length(); 
        int answer = 0; 
        Set<Character> hashSet = new HashSet<>(); 


        for(char c : source.toCharArray()){
            hashSet.add(c); 
        }
        while(targetIndex < n){
            char curr = target.charAt(targetIndex); 

            if(!hashSet.contains(curr)) return -1; 

            while(sourceIndex < m && targetIndex < n){
                if(source.charAt(sourceIndex) == target.charAt(targetIndex)){
                    sourceIndex++;
                    targetIndex++; 
                } else{
                    sourceIndex++; 
                }
            }

            answer++; 
            sourceIndex = 0; 
        }

        return answer; 

    }
}