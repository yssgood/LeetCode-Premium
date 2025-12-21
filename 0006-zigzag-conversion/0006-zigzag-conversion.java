class Solution {
    public String convert(String s, int numRows) {
        Map<Integer, StringBuilder> hashMap = new HashMap<>(); 
        int row = 0; 
        boolean isEnd = false; 
        for(char c : s.toCharArray()){
            hashMap.computeIfAbsent(row, k -> new StringBuilder()).append(c); 
            
            if(!isEnd){
                row++; 
            } else{
                row--; 
            }

            if(row >= numRows){
                row-=2; 
                isEnd = !isEnd; 
            } else if(row < 0){
                row+=2;
                isEnd = !isEnd; 
            }
        }


        StringBuilder answer = new StringBuilder(); 
        for(Map.Entry<Integer,StringBuilder> entry : hashMap.entrySet()){
            answer.append(entry.getValue()); 
        }

        return answer.toString(); 
    }
}