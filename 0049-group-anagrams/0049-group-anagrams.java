class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> answer = new ArrayList<>(); 
        HashMap<String,List<String>> hashMap = new HashMap<>(); 
        for(String s : strs){
            char[] charArr = s.toCharArray(); 
            Arrays.sort(charArr); 
            String tmp = new String(charArr); 
            if(!hashMap.containsKey(tmp)){
                hashMap.put(tmp, new ArrayList<>());
            }
            hashMap.get(tmp).add(s); 
        }

        for(String s : hashMap.keySet()){
            answer.add(hashMap.get(s)); 
        }

        return answer; 
    }
}