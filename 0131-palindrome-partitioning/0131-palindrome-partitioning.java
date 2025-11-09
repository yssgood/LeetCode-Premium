class Solution {
    public List<List<String>> partition(String s) {
        List<List<String>> answer = new ArrayList<>(); 
        List<String> container = new ArrayList<>(); 
        dfs(s,answer,container,0); 
        return answer; 
    }
    void dfs(String s, List<List<String>> answer, List<String> container, int index){
        if(index >= s.length()){
            if(container.size() > 0) answer.add(new ArrayList<>(container)); 
            return; 
        }

        for(int i = index; i < s.length(); i++){
            String subString = s.substring(index,i+1); 
            if(isPalindrome(subString)){
                container.add(subString); 
                dfs(s,answer,container,i+1); 
                container.removeLast(); 
            }
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


//Time : O(N^2) 
//Space : O(N); 