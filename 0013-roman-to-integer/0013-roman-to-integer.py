class Solution:
    def romanToInt(self, s: str) -> int:
        hashMap = {'I' : 1, 'V' : 5, 'X' : 10, 'L' : 50, 'C' : 100, 'D' : 500, 'M' : 1000} 
        answer = hashMap[s[0]] 

        for i in range(1,len(s)):
            prev = hashMap[s[i-1]]
            curr = hashMap[s[i]] 

            if(prev < curr):
                answer -= prev 
                curr -= prev 
            
            answer += curr 

        
        return answer