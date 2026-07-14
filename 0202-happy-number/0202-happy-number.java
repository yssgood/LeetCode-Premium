class Solution {
    public boolean isHappy(int n) {
        Map<Integer,Boolean> map = new HashMap<>(); 
        while(n > 1){
            int tmp = n; 
            int nextDigit = 0; 
            while(tmp > 0){
                int lastDigit = tmp % 10; 
                tmp /= 10; 
                nextDigit += lastDigit * lastDigit; 
            }
            n = nextDigit; 
            //System.out.println(n); 
            if(map.containsKey(n)) return false; 
            map.put(n,true); 
        }
        return true; 
    }
}