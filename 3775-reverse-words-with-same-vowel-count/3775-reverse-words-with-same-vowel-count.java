class Solution {
    public String reverseWords(String s) {
        Set<Character> vowels = Set.of('a', 'e', 'i', 'o', 'u'); 
        Set<Integer> visited = new HashSet<>(); 
        StringBuilder answer = new StringBuilder(); 
        String[] arr = s.split(" "); 
        for(String ss : arr){
            StringBuilder sb = new StringBuilder(ss); 
            int count = 0; 
            for(char c : sb.toString().toCharArray()){
                if(vowels.contains(c)) count++; 
            }
            if(visited.contains(count)){
                sb.reverse(); 
            }
            if(visited.isEmpty()) visited.add(count); 
            answer.append(sb.toString()).append(" "); 
        }

        answer.deleteCharAt(answer.length()-1); 

        return answer.toString(); 
    }
}