class Solution {
        private final Map<Character,List<Character>> hashMap = Map.of('2', Arrays.asList('a','b','c'), '3', Arrays.asList('d','e','f'), '4', Arrays.asList('g','h','i'), '5', Arrays.asList('j','k','l'), '6', Arrays.asList('m','n','o'), '7', Arrays.asList('p','q','r','s'), '8', Arrays.asList('t','u','v'), '9', Arrays.asList('w','x','y','z')); 
    public List<String> letterCombinations(String digits) {
        List<String> answer = new ArrayList<>(); 
        StringBuilder sb = new StringBuilder(); 
        dfs(digits,answer,0,sb);
        return answer; 
    }
    public void dfs(String digits, List<String> answer, int index, StringBuilder sb){
        if(index >= digits.length()){
            answer.add(sb.toString()); 
            return; 
        }

        for(int i = 0; i < hashMap.get(digits.charAt(index)).size(); i++){
            sb.append(hashMap.get(digits.charAt(index)).get(i)); 
            dfs(digits, answer, index + 1, sb); 
            sb.deleteCharAt(sb.length()-1); 
        }
    }
}