class Solution {
    public String stringShift(String s, int[][] shift) {
        StringBuilder sb = new StringBuilder(s); 
        for(int[] p : shift){
            int dir = p[0]; 
            int len = p[1] % s.length(); 

            if(dir == 0){
                String left = sb.substring(0, len); 
                String right = sb.substring(len); 
                sb = new StringBuilder(right + left); 
            } else{
                String left = sb.substring(sb.length() - len); 
                String right = sb.substring(0, sb.length() - len); 
                sb = new StringBuilder(left + right); 
                //System.out.print(sb.toString()); 
            }
        }

        return sb.toString();
    }
}