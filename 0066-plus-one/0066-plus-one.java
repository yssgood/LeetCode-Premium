class Solution {
    public int[] plusOne(int[] digits) {
        List<Integer> answer = new ArrayList<>(); 
        int sum = (digits[digits.length-1] + 1) % 10; 
        int carry = (digits[digits.length-1] + 1) / 10; 
        answer.add(sum); 
        for(int i = digits.length-2; i >= 0;  i--){
            sum = (digits[i] + carry) % 10; 
            carry = (digits[digits.length-1] + 1) / 10;
            answer.add(sum); 
        }
        if(carry > 0) answer.add(1); 
        int[] res = new int[answer.size()]; 
        Collections.reverse(answer); 
        for(int i = 0; i < answer.size(); i++) res[i] = answer.get(i); 
        return res;  
    }
}