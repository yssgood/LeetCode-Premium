class Solution {
    public String rankTeams(String[] votes) {
        Map<Character,int[]> hashMap = new HashMap<>(); 
        List<Character> lst = new LinkedList<>(); 
        for(char c : votes[0].toCharArray()){
            //hashMap[c] = new int[votes[0].length()]; 
            hashMap.put(c, new int[votes[0].length()]);
            lst.add(c); 
        }
        
        for(String s : votes){
            for(int i = 0; i < s.length(); i++){
                hashMap.get(s.charAt(i))[i]++; 
            }
        }
        

        Collections.sort(lst,(a,b)->{
            for(int i = 0; i < hashMap.get(a).length; i++){
                if(hashMap.get(a)[i] > hashMap.get(b)[i]){
                    return -1; 
                }
                else if(hashMap.get(a)[i] < hashMap.get(b)[i]){
                    return hashMap.get(b)[i] - hashMap.get(a)[i]; 
                }
            }
            return a.compareTo(b); 
        });
        
        StringBuilder answer = new StringBuilder(); 
        for(Character c : lst){
            answer.append(c); 
        }
        
        return answer.toString(); 
    }
}