class Solution:
    def reverseWords(self, s: str) -> str:
        s = s[::-1] 
        start = 0
        end = 0 
        answer = "" 
        while(end < len(s)):
            while(start < len(s) and s[start].isspace()) : start += 1
            end = start 
            while(end < len(s) and s[end].isalnum()) : end += 1 
            
            tmp = s[start:end]
            tmp = tmp[::-1]
            if len(tmp) > 0 : answer += tmp + " "
            start = end 
        
        answer = answer[:len(answer)-1]
        return answer