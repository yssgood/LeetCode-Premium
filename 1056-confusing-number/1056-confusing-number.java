class Solution {
    public boolean confusingNumber(int n) {
        Map<Integer,Integer> hashMap = Map.of(6,9, 9,6); 
        Set<Integer> set = Set.of(2,3,4,5,7); 
        int answer = 0; 
        int original = n; 
        while(n > 0){
            int lastDigit = n % 10; 
            if(set.contains(lastDigit)) return false; 
            if(hashMap.containsKey(lastDigit)){
                answer = (answer * 10) + (hashMap.get(lastDigit)); 
            } else{
                answer = (answer * 10) + lastDigit; 
            }
            n /= 10; 
        }

        //System.out.print(answer); 
        return answer != original; 
    }
}