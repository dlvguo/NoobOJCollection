class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for i in s:
            if i == '{' or i == '[' or i == '(':
                stack.append(i)
            elif len(stack) == 0:
                return False
            else:
                c = stack.pop()
                if i == ']':
                    if c != '[':
                        return False
                elif i == '}':
                    if c != '{':
                        return False
                elif c != '(':
                    return False
        return True if len(stack) == 0 else False