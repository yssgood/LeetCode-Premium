class Solution {
    public List<String> fizzBuzz(int n) {
        List<String> answer = new ArrayList<>(); 
        
        for(int i = 1; i <= n; i++){
            String word;
            if(i % 3 == 0 && i % 5 == 0){
                word = "FizzBuzz"; 
            } else if(i % 3 ==0){
                word = "Fizz"; 
            } else if(i % 5 == 0){
                word = "Buzz"; 
            } else{
                word = String.valueOf(i); 
            }
            answer.add(word); 
        }

        return answer; 
    }
}