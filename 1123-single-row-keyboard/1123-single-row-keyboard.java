class Solution {
    public int calculateTime(String keyboard, String word) {
        HashMap<Character,Integer> hashMap = new HashMap<>(); 
        for(int i = 0; i < keyboard.length(); i++){
            hashMap.put(keyboard.charAt(i), i); 
        }
        int answer = 0, curr = 0; 
        for(Character c : word.toCharArray()){
            answer += Math.abs(curr - hashMap.get(c)); 
            curr = hashMap.get(c); 
        }
        return answer; 
    }
}