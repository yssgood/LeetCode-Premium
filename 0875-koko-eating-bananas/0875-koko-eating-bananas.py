class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        left = 1 
        right = max(piles) 

        answer = 0

        while left <= right:
            k = left + (right - left) // 2 

            time = 0 
            for num in piles:
                time += (num // k) 
                time += 1 if num % k > 0 else 0

            if time <= h:
                answer = k  
                right = k - 1 
            else: 
                left = k + 1 

        return answer 
