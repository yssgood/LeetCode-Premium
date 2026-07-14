class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> answer = new ArrayList<>(); 
        Map<String, List<String>> hashMap = new HashMap<>(); 
        for(String s : strs){
            char[] toChar = s.toCharArray(); 
            Arrays.sort(toChar); 
            String key = new String(toChar); 

            hashMap.computeIfAbsent(key, k -> new ArrayList<>()).add(s); 
        }

        for(var e : hashMap.entrySet()){
            answer.add(e.getValue()); 
        }
        return answer; 
    }
}