class Solution {
    String convert(String s){
        StringBuilder sb = new StringBuilder(); 
        sb.append('0'); 
        for(int i = 1; i < s.length(); i++){
            //Character tmp = (char)(((s.charAt(i) - s.charAt(i-1) + 26) % 26) + '0'); 
            //char tmp = (char)(((s.charAt(i) - s.charAt(i - 1) + 26) % 26) + '0');
            int diff = s.charAt(i) - s.charAt(i-1) < 0 ? (s.charAt(i) - s.charAt(i-1)) + 26 : s.charAt(i) - s.charAt(i-1); 
            
            sb.append((char)(diff + '0')); 
        }
        return sb.toString(); 
    }
    public List<List<String>> groupStrings(String[] strings) {
        List<List<String>> answer = new ArrayList<>(); 
        HashMap<String,List<String>> hashMap = new HashMap<>(); 
        for(String s : strings){
            String pattern = convert(s); 
            //System.out.println(pattern); 
            if(hashMap.containsKey(pattern)){
                List<String> tmp = hashMap.get(pattern); 
                tmp.add(s); 
                hashMap.put(pattern, tmp); 
            } else{
                List<String> ls = new ArrayList<>(); 
                ls.add(s); 
                hashMap.put(pattern, ls); 
            }
        }

        for(String s : hashMap.keySet()){
            List<String> ls = hashMap.get(s); 
            answer.add(ls); 
        }

        return answer; 
    }
}