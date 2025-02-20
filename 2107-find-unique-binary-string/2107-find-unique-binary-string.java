class Solution {
    HashMap<String,Boolean> hashMap = new HashMap<>(); 
    List<Character> lst = Arrays.asList('0','1'); 
    String answer = ""; 
    public void dfs(StringBuilder sb, int n){
        if(sb.length() == n){
            if(!hashMap.containsKey(sb.toString())) answer = sb.toString(); 
            return; 
        }

        for(int i = 0; i < lst.size(); i++){
            sb.append(lst.get(i)); 
            dfs(sb,n); 
            sb.deleteCharAt(sb.length()-1); 
        }
    }
    public String findDifferentBinaryString(String[] nums) {
        for(String s : nums) hashMap.put(s,true); 

        StringBuilder sb = new StringBuilder(); 
        int n = nums[0].length(); 
        dfs(sb,n); 
        return answer; 
    }
}