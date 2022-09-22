class Solution:
    def removeOccurrences(self, s: str, part: str) -> str:
        stack = []
        if len(part)>len(s):
            return s
        for i in range(len(part)):
            stack.append(s[i])
        i = len(part)
        while i<len(s):
            #print(''.join(stack[len(stack)-len(part):]))
            while len(stack)>=len(part) and ''.join(stack[len(stack)-len(part):]) == part:
                k = 0
                while k<len(part):
                    stack.pop()
                    k+=1
            stack.append(s[i])
            i+=1
        if len(stack)>=len(part) and ''.join(stack[len(stack)-len(part):]) == part:
            k = 0
            while k<len(part):
                stack.pop()
                k+=1
        return ''.join(stack)