class Solution {
    public boolean confusingNumber(int n) {
        int answer = 0; 
        int copy = n; 
        Set<Integer> s = new HashSet<>(); 
        s.add(2);
        s.add(3);
        s.add(4);
        s.add(5);
        s.add(7); 
        while(n > 0){
            answer *= 10; 
            int rem = n % 10; 
            if(rem == 6){
                rem = 9; 
            } else if(rem == 9){
                rem = 6; 
            } else if(s.contains(rem)){
                return false; 
            }
            answer += rem; 
            n /= 10; 
        }
        
        return copy != answer; 
    }
}