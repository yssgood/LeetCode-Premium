class Solution {
    public String rankTeams(String[] votes) {
        Map<Character,int[]> hashMap = new HashMap<>(); 
        for(String s : votes){
            for(int i = 0; i < s.length(); i++){
                hashMap.computeIfAbsent(s.charAt(i), k -> new int[s.length()])[i]++; 
            }
        }

        String tmp = votes[0]; 
        List<Character> lst = new ArrayList<>(); 
        for(char c : tmp.toCharArray()) lst.add(c); 

        lst.sort((a,b) -> {
            int[] arrA = hashMap.get(a); 
            int[] arrB = hashMap.get(b); 

            for(int i = 0; i < arrA.length; i++){
                if(arrA[i] != arrB[i]) return Integer.compare(arrB[i], arrA[i]); 
            }

            return Character.compare(a,b); 
        }
        );

        StringBuilder sb = new StringBuilder(); 
        for(char c : lst) sb.append(c); 
        return sb.toString(); 
    }
}