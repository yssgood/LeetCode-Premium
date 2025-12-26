class Solution {
    public String rankTeams(String[] votes) {
        Map<Character, int[]> hashMap = new HashMap<>(); 
        String answer = votes[0]; 
        for(String s : votes){
            for(int i = 0; i < s.length(); i++){
                hashMap.computeIfAbsent(s.charAt(i), k -> new int[s.length()])[i]++; 
            }
        }

        char[] charArr = answer.toCharArray();
        List<Character> lst = new ArrayList<>(); 
        for(char c : charArr) lst.add(c); 
        Collections.sort(lst, (a,b) -> {
            int[] forA = hashMap.get(a); 
            int[] forB = hashMap.get(b); 
            for(int i = 0; i < forA.length; i++){
                if(forA[i] != forB[i]){
                    return forB[i] - forA[i]; 
                }
                // if(forA[i] > forB[i]){
                //     return forA[i] - forB[i]; 
                // }
                // if(forB[i] < forA[i]){
                //     return forB[i] - forA[i]; 
                // }
            }

            return a - b; 
        });

        char[] res = new char[answer.length()];  
        for(int i = 0; i < res.length; i++){
            res[i] = lst.get(i); 
        }

        answer = new String(res); 

        return answer; 
    }
}