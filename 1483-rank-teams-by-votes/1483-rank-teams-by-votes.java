class Solution {
    public String rankTeams(String[] votes) {
        Map<Character,int[]> hashMap = new HashMap<>(); 
        
        for(String s : votes){
            for(int i = 0; i < s.length(); i++){
                hashMap.computeIfAbsent(s.charAt(i), k -> new int[votes[0].length()])[i]++; 
            }
        }

        char[] toChar = votes[0].toCharArray(); 
        List<Character> lst = new ArrayList<>(); 
        for(char c : toChar) lst.add(c); 

        Collections.sort(lst, (a,b) -> {
            int[] rankA = hashMap.get(a); 
            int[] rankB = hashMap.get(b); 
            for(int i = 0; i < votes[0].length(); i++){
                if(rankA[i] != rankB[i]){
                    return rankB[i] - rankA[i]; 
                }
            }

            return a - b; 
        }); 

        StringBuilder sb = new StringBuilder(); 
        for(char c : lst){
            sb.append(c); 
        }

        return sb.toString(); 
    }
}