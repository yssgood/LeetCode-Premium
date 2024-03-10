class Solution {
    public int calculateTime(String keyboard, String word) {
        HashMap<Character,Integer> hashMap = new HashMap<>(); 
        int answer = 0, currChar = 0; 
        for(int i = 0; i < 26; i++){
            hashMap.put(keyboard.charAt(i), i);  
        }

        for(char c : word.toCharArray()){
            int next = hashMap.get(c); 
            //System.out.print(currChar); 
            //System.out.println(next); 
            answer += Math.abs(currChar - next); 
            
            currChar = next; 
        }

        return answer; 
    }
}