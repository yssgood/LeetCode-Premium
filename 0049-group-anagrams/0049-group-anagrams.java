class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String,List<String>> hashMap = new HashMap<>(); 
        
        for(String s : strs){
            char[] chars = s.toCharArray(); 
            Arrays.sort(chars); 
            String tmp = new String(chars); 

            hashMap.computeIfAbsent(tmp, a -> new ArrayList<>()).add(s); 

        }

        List<List<String>> answer = new ArrayList<>(); 
        for(List<String> val : hashMap.values()){
            answer.add(val); 
        }

        return answer; 
    }
}