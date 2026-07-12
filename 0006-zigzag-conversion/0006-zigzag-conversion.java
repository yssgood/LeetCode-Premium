class Solution {
    public String convert(String s, int numRows) {
        if(numRows == 1) return s; 
        StringBuilder[] sbArray = new StringBuilder[numRows]; 
        for(int i = 0; i < numRows; i++){
            sbArray[i] = new StringBuilder(); 
        }

        int curr = 0; 
        int dir = 1; 
        for(char c : s.toCharArray()){
            sbArray[curr].append(c); 
            
            if(dir == 1){
                if(curr + 1 >= numRows){
                    curr--; 
                    dir = -1; 
                } else{
                    curr++; 
                }
            } else if(dir == -1){
                if(curr - 1 < 0){
                    curr++; 
                    dir = 1; 
                } else{
                    curr--; 
                }
            }
        }
        //System.out.print(Arrays.toString(sbArray)); 
        return String.join("", sbArray); 
    }
}