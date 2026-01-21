class Solution {
    public String frequencySort(String s) {
        Map<Character,Integer> hashMap = new HashMap<>(); 
        for(char c : s.toCharArray()) hashMap.put(c, hashMap.getOrDefault(c,0) + 1); 
        List<Character> charList = new ArrayList<>(); 
        for(char c : s.toCharArray()) charList.add(c); 
        Collections.sort(charList, (a,b) -> {
            int freqA = hashMap.get(a);
            int freqB = hashMap.get(b); 
            if(freqB == freqA){
                return b - a;  
            }
            return freqB - freqA; 
        });

        StringBuilder sb = new StringBuilder(); 
        for(char c : charList){
            sb.append(c); 
        }


        return sb.toString(); 
    }
}