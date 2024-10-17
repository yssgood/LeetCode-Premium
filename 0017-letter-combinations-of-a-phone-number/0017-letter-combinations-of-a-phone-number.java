class Solution {
    void dfs(String digits, int index, List<String> answer,StringBuilder sb,Map<Character,List<Character>> hashMap){
        if(sb.length() >= digits.length()){
            answer.add(new String(sb.toString())); 
            return; 
        }

        for(int i = 0; i < hashMap.get(digits.charAt(index)).size(); i++){
            sb.append(hashMap.get(digits.charAt(index)).get(i)); 
            dfs(digits,index+1,answer,sb,hashMap); 
            sb.deleteCharAt(index); 
        }
    }
    public List<String> letterCombinations(String digits) {
        if(digits.isEmpty()){
            return Collections.emptyList(); 
        }
        List<String> answer = new ArrayList<>(); 
        Map<Character, List<Character>> hashMap = new HashMap<>() {{
            put('2', Arrays.asList('a', 'b', 'c'));
            put('3', Arrays.asList('d', 'e', 'f'));
            put('4', Arrays.asList('g', 'h', 'i'));
            put('5', Arrays.asList('j', 'k', 'l'));
            put('6', Arrays.asList('m', 'n', 'o'));
            put('7', Arrays.asList('p', 'q', 'r', 's'));
            put('8', Arrays.asList('t', 'u', 'v'));
            put('9', Arrays.asList('w', 'x', 'y', 'z'));
        }};
        StringBuilder sb = new StringBuilder(); 
        dfs(digits,0,answer,sb,hashMap); 

        return answer; 
    }
}