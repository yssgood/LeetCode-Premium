class Solution {
    public List<List<String>> partition(String s) {
        List<List<String>> answer = new ArrayList<>(); 
        List<String> container = new ArrayList<>(); 
        dfs(answer,container,0, s);
        return answer; 
    }
    public void dfs(List<List<String>> answer, List<String> container, int index, String s){
        if(index >= s.length()){
            answer.add(new ArrayList<>(container)); 
            return; 
        }

        for(int i = index; i < s.length(); i++){
            String tmp = s.substring(index, i + 1); 
            if(isPalindrome(tmp)){
                container.add(tmp); 
                dfs(answer,container,i+1,s);
                container.removeLast(); 
            }
        }
    }

    public boolean isPalindrome(String tmp){
        int start = 0, end = tmp.length()-1; 
        while(start < end){
            if(tmp.charAt(start) != tmp.charAt(end)){
                return false; 
            }
            start++;
            end--; 
        }
        return true; 
    }
}