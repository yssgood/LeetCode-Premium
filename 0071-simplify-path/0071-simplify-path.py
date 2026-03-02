class Solution:
    def simplifyPath(self, path: str) -> str:
        stack = [] 
        index = 0 
        while(index < len(path)):
            tmp = "" 
            tmpIndex = index 
            while(tmpIndex < len(path) and path[tmpIndex] != '/'):
                tmpIndex += 1
            
            if tmpIndex - index > 0:
                tmp = path[index:tmpIndex] 
                
                if tmp == '.' or tmp == '..':
                    if tmp == '..' and stack : stack.pop() 
                else:
                    stack.append(tmp) 
                
            index = tmpIndex
            index += 1

        answer = "" 
        
        while stack:
            answer += stack.pop()[::-1] + "/" 
        
        answer = answer[::-1] 

        return answer if len(answer) > 0 else "/"