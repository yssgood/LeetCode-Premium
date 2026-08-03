class Solution:
    def decodeString(self, s: str) -> str:
        stack = [] 
        numStack = [] 
        num = 0 
        currString = ""

        for ch in s:
            if ch.isdigit(): 
                num = num * 10 + int(ch) 
            elif ch == '[':
                stack.append(currString) 
                numStack.append(num) 
                num = 0 
                currString = ""
            elif ch == ']': 
                prev = numStack.pop()
                currString = stack.pop() + (currString * prev) 
            else:
                currString += ch 
        return currString