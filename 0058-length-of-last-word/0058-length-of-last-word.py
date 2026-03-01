class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        lastIndex = len(s)-1 
        numChar = 0
        while(lastIndex >= 0):
            if numChar > 0 and s[lastIndex].isspace():
                return numChar 
            
            numChar += 1 if s[lastIndex].isalpha() else 0
            lastIndex -= 1 
        return numChar