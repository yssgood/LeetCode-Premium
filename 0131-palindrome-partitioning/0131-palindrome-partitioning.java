class Solution {
    public List<List<String>> partition(String s) {
        List<List<String>> answer = new ArrayList<>(); 
        List<String> container = new ArrayList<>(); 
        dfs(s,container,answer,0); 
        return answer; 
    }
    void dfs(String s, List<String> container, List<List<String>> answer, int index){
        if(index == s.length()){
            answer.add(new ArrayList<>(container)); 
            return; 
        }

        for(int i = index; i < s.length(); i++){
            String candidate = s.substring(index, i + 1); 
            if(isPalindrome(candidate)){
                container.add(candidate); 
                dfs(s,container,answer,i+1); 
                container.removeLast(); 
            }
            //String candidate = s.substring(i,i+1) //? 
            //check if they are parition 
            //add it to my contianer
            //do the backtracking to the next character 
            //pop the existing element 
        }
    }
    boolean isPalindrome(String s){
        int start = 0, end = s.length()-1;
        while(start < end){
            if(s.charAt(start) != s.charAt(end)) return false;
            start++; 
            end--; 
        }
        return true; 
    }
}