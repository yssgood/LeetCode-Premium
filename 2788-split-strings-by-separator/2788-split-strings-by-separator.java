class Solution {
    public List<String> splitWordsBySeparator(List<String> words, char separator) {
        List<String> answer = new ArrayList<>(); 
        for(String word : words){
            StringBuilder sb = new StringBuilder(); 
            for(char c : word.toCharArray()){
                if(c != separator){
                    sb.append(c); 
                } else{
                    if(sb.length() > 0) answer.add(sb.toString()); 
                    sb = new StringBuilder(); 
                }
            }

            if(sb.length() > 0) answer.add(sb.toString()); 
        }

        return answer; 
    }
}