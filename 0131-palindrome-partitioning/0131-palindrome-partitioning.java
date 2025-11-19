class Solution {
    public List<List<String>> partition(String s) {
        List<List<String>> answer = new ArrayList<>(); 
        List<String> container = new ArrayList<>(); 
        dfs(s,answer,container,0); 
        return answer; 
    }
    void dfs(String s, List<List<String>> answer, List<String> container, int index){
        if(index >= s.length()){
            answer.add(new ArrayList<>(container)); 
            return; 
        }
        for(int i = index; i < s.length(); i++){
            String tmp = s.substring(index, i + 1);
            if(isPalindrome(tmp)){
                container.add(tmp); 
                dfs(s, answer, container, i + 1); 
                container.removeLast(); 
            }
        }
    }

    boolean isPalindrome(String tmp){
        int start = 0, end = tmp.length()-1; 
        while(start < end){
            if(tmp.charAt(start) != tmp.charAt(end)) return false;
            start++;
            end--; 
        }
        return true; 
    }
}