class Solution {
    public int mySqrt(int x) {
        if(x < 2) return x; 
        int answer = 0; 
        for(int i = 1; i <= x; i++){
            long square = (long) i * i; 
            if(square > x) break; 
            answer = i; 
        }
        return answer; 
    }
}