class Solution {
    public int romanToInt(String s) {
        Map<Character,Integer> hashMap = Map.of('I',1, 'V',5, 'X',10, 'L',50, 'C',100, 'D',500, 'M',1000); 
        int answer = hashMap.get(s.charAt(0)); 

        for(int i = 1; i < s.length(); i++){
            int lastChar = hashMap.get(s.charAt(i-1)); 
            int currChar = hashMap.get(s.charAt(i)); 

            if(lastChar < currChar){
                answer -= lastChar; 
                currChar -= lastChar; 
            }
            
            answer += currChar; 
        }
        

        return answer; 
    }
}