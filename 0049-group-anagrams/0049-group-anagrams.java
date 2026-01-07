class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> answer = new ArrayList<>(); 
        Map<String, List<String>> hashMap = new HashMap<>(); 

        for(String s : strs){
            char[] charArr = s.toCharArray(); 
            Arrays.sort(charArr); 
            String sortedString = new String(charArr); 
            hashMap.computeIfAbsent(sortedString, k -> new ArrayList<>()).add(s); 
        }

        for(Map.Entry<String, List<String>> entry : hashMap.entrySet()){
            answer.add(entry.getValue()); 
        }
        return answer; 
    }
}