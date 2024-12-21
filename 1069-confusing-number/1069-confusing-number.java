class Solution {
    public boolean confusingNumber(int n) {
        int answer = 0;
        int tmp = n; 
        Set<Integer> banned = new HashSet<>(Set.of(2,3,4,5,7)); 
        while(n > 0){
            int last = n % 10; 
            if(banned.contains(last)) return false; 

            if(last == 6){
                answer += 9; 
            } else if(last == 9){
                answer += 6;
            } else{
                answer += last; 
            }

            n /= 10; 
            answer *= 10; 
        }
        answer /= 10; 
        return answer != tmp; 
    }
}