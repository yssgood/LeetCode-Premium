from collections import defaultdict 
class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        hashMap = {')' : '(', ']' : '[', '}' : '{'}

        for char in s:

            if char in hashMap:
                if stack and stack[-1] == hashMap[char]:
                    stack.pop()
                else:
                    return False
            else:
                stack.append(char) 

        return not stack
                