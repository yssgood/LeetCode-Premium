class Solution {
    public String addStrings(String num1, String num2) {
        int p1 = num1.length()-1; 
        int p2 = num2.length()-1;
        StringBuilder sb = new StringBuilder();  
        int firstNum = 0;
        int secondNum = 0; 
        int carry = 0; 
        while(p1 >= 0 || p2 >= 0){
            if(p1 >= 0){
                firstNum = num1.charAt(p1) - '0'; 
            } else{
                firstNum = 0; 
            }

            if(p2 >= 0){
                secondNum = num2.charAt(p2) - '0'; 
            } else{
                secondNum = 0; 
            }

            int sum = (firstNum + secondNum + carry) % 10; 
            carry = (firstNum + secondNum + carry) / 10; 
            //System.out.println(firstNum + " " + secondNum + " " + (sum / 10)); 
            sb.append(Integer.toString(sum)); 
            p1--;
            p2--; 
        }
        if(carry > 0) sb.append('1'); 
        sb.reverse(); 
        return sb.toString(); 
    }
}