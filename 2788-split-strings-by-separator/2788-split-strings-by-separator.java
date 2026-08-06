class Solution {
    public List<String> splitWordsBySeparator(List<String> words, char separator) {
        List<String> answer = new ArrayList<>(); 
        for(String s : words){
            String[] arr = s.split("\\"+separator); 
            for(String ss : arr) if(!ss.isEmpty()) answer.add(ss); 
        }
        return answer; 
    }
}