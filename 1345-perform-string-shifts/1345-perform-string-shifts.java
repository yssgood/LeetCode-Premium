class Solution {
    public String stringShift(String s, int[][] shift) {
        StringBuilder sb = new StringBuilder(s); 
        for(int i = 0; i < shift.length; i++){
            int dir = shift[i][0];  
            int index = shift[i][1] % s.length(); 

            if(dir == 0){
                sb = new StringBuilder(sb.substring(index)).append(sb.substring(0,index));
            } else{
                sb = new StringBuilder(sb.substring(sb.length() - index)).append(sb.substring(0,sb.length() - index)); 
            }
        }

        return sb.toString(); 
    }
}