class Solution {
    public String rankTeams(String[] votes) {
        Map<Character,int[]> hashMap = new HashMap<>(); 
        for(int i = 0; i < votes[0].length(); i++){
            hashMap.put(votes[0].charAt(i), new int[votes[0].length()]);
        }

        for(String s : votes){
            for(int i = 0; i < s.length(); i++){
                // int[] vec = hashMap.get(s.charAt(i)); 
                // vec[i]++; 
                // hashMap.put(s.charAt(i), vec); 
                hashMap.computeIfAbsent(s.charAt(i), k -> new int[votes[0].length()])[i]++; 
            }
        }

        String first = votes[0]; 
        char[] tmp = first.toCharArray(); 
        List<Character> lst = new ArrayList<>(); 
        for(char c : tmp) lst.add(c); 
        
        Collections.sort(lst,(a,b) -> {
            int[] arrA = hashMap.get(a); 
            int[] arrB = hashMap.get(b); 

            for(int i = 0; i < arrA.length; i++){
                if(arrA[i] != arrB[i]){
                    return arrB[i] - arrA[i]; 
                }
            }

            return a - b; 
        });


        StringBuilder sb = new StringBuilder(); 
        for(char c : lst) sb.append(c); 


        return sb.toString(); 
    }
}