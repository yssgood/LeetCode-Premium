class Solution {
    public int countOperations(int num1, int num2) {
        if(num1 == 0 || num2 == 0) return 0; 
        int count = 0;  
        while(num1 > 0 && num2 > 0){
            if(num1 >= num2){
                num1 -= num2; 
            } else{
                num2 -= num1; 
            }
            count++; 
            if(num1 <= 0 || num2 <= 0) return count; 

            // System.out.print(num1 + " "); 
            // System.out.println(num2); 
        }
        return count; 
    }
}