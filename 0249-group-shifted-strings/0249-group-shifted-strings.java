class Solution {
    public List<List<String>> groupStrings(String[] strings) {
        List<List<String>> answer = new ArrayList<>(); 
        Map<String,List<String>> hashMap = new HashMap<>();
        
        for(String s : strings){
            String key = convert(s); 
            hashMap.computeIfAbsent(key, k -> new ArrayList<>()).add(s); 
        }

        for(var e : hashMap.entrySet()){
            answer.add(e.getValue()); 
        }

        return answer; 
    }

    public String convert(String s){
        String key = "1"; 
        for(int i = 1; i < s.length(); i++){
            int diff = (s.charAt(i) - s.charAt(i-1) + 26) % 26;   // 이 줄만 변경
            key += String.valueOf(diff) + ","; 
        }
        //System.out.println(key); 
        return key; 
    }
}