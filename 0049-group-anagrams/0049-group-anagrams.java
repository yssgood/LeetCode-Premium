class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> answer = new ArrayList<>(); 
        Map<String,List<String>> hashMap = new HashMap<>(); 
        for(String s : strs){
            char[] tmp = s.toCharArray(); 
            Arrays.sort(tmp); 
            String newS = new String(tmp); 
            hashMap.computeIfAbsent(newS, k -> new ArrayList<>()).add(s); 
        }
        for(List<String> lst : hashMap.values()){
            answer.add(lst); 
        }
        return answer; 
    }
}