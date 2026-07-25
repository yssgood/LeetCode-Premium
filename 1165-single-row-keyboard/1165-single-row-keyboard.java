class Solution {
    public int calculateTime(String keyboard, String word) {
        Map<Character,Integer> hashMap = new HashMap<>(); 
        for(int i = 0; i < keyboard.length(); i++){
            hashMap.put(keyboard.charAt(i), i); 
        }

        int answer = 0;
        int curr = 0;  
        for(char c : word.toCharArray()){
            answer += Math.abs(hashMap.get(c) - curr); 
            curr = hashMap.get(c); 
        }
        return answer; 
    }
}