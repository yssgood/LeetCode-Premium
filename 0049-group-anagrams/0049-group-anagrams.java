class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> answer = new ArrayList<>(); 
        Map<String,List<String>> hashMap = new HashMap<>(); 
        for(String s : strs){
            char[] tmp = s.toCharArray(); 
            Arrays.sort(tmp);
            String key = new String(tmp); 
            hashMap.computeIfAbsent(key, k -> new ArrayList<>()).add(s); 
        }
        for(List<String> ss : hashMap.values()){
            answer.add(ss); 
        }
        return answer; 
    }
}