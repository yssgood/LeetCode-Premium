class Solution {
    public int sumFourDivisors(int[] nums) {
        int totalSum = 0;
        
        for (int num : nums) {
            int divisorSum = getDivisorSum(num);
            totalSum += divisorSum;
        }
        
        return totalSum;
    }
    
    private int getDivisorSum(int n) {
        int count = 0;
        int sum = 0;
        
        // check divisors up to sqrt(n)
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                count++;
                sum += i;
                
                // add the paired divisor if different
                if (i != n / i) {
                    count++;
                    sum += n / i;
                }
                
                // early exit if more than 4 divisors
                if (count > 4) {
                    return 0;
                }
            }
        }
        
        return count == 4 ? sum : 0;
    }
}