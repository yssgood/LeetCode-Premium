class Solution {
    public boolean wordPattern(String pattern, String s) {
        String[] sList = s.split(" "); 
        Map<Character,String> hashMap = new HashMap<>(); 
        Set<String> mapped = new HashSet<>(); 
        if(pattern.length() != sList.length) return false; 
        
        for(int i = 0; i < pattern.length(); i++){
            char left = pattern.charAt(i); 
            String mappingString = sList[i]; 
            if(hashMap.containsKey(left) && !hashMap.get(left).equals(mappingString)) return false; 
            if(!hashMap.containsKey(left) && mapped.contains(mappingString)) return false; 
            hashMap.put(left, mappingString); 
            mapped.add(mappingString);
        }
        return true; 
    }
}