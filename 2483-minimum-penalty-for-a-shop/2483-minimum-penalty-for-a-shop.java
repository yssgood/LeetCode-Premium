class Solution {
    public int bestClosingTime(String customers) {
        int total = 0; 
        for(char c  : customers.toCharArray()){
            if(c == 'Y') total++; 
        }

        int[] penalty = new int[]{0,total}; 
        if(total == 0) return 0; 

        for(int i = 0; i < customers.length(); i++){
            char curr = customers.charAt(i); 
            if(curr == 'Y') total--; 
            if(curr == 'N') total++; 

            if(total < penalty[1]){
                penalty[0] = i + 1; 
                penalty[1] = total; 
            }
        }

        return penalty[0]; 

    }
}