class Solution {
    public int[] plusOne(int[] digits) {
        List<Integer> answer = new ArrayList<>(); 
        int offset = (digits[digits.length-1] + 1) / 10; 
        answer.add((digits[digits.length-1] + 1) % 10); 
        for(int i = digits.length-2; i >= 0; i--){
            int sum = digits[i] + offset; 
            answer.add(sum % 10); 
            offset = sum >= 10 ? 1 : 0; 
        }

        if(offset > 0) answer.add(1); 

        Collections.reverse(answer);

        return answer.stream().mapToInt(i -> i).toArray(); 
    }
}