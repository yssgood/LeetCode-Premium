class Solution {
    public List<List<String>> partition(String s) {
        List<List<String>> answer = new ArrayList<>(); 
        List<String> container = new ArrayList<>(); 
        dfs(s,answer,container,0);
        return answer; 
    }
    public void dfs(String s, List<List<String>> answer, List<String> container, int index){
        if(index >= s.length()){
            answer.add(new ArrayList<>(container)); 
            return; 
        }

        for(int i = index; i < s.length(); i++){
            String tmp = s.substring(index, i + 1); 
            if(palindrome(tmp)){
                container.add(tmp); 
                dfs(s,answer,container,i+1); 
                container.removeLast(); 
            }
        }
    }

    public boolean palindrome(String s){
        int left = 0, right = s.length()-1; 
        while(left < right){
            if(s.charAt(left) != s.charAt(right)) return false; 

            left++;
            right--; 
        }

        return true; 
    }
}