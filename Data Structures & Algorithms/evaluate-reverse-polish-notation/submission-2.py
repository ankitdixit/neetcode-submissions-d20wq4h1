class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        res = 0
        operators = ['+', '-', '*', '/']
        stack = []
        for c in tokens:
            if c in operators:
                a = int(stack.pop())
                b = int(stack.pop())
                if c == '+':
                    stack.append(a+b)
                elif c == '-':
                    stack.append(b - a)
                elif c == '*':
                    stack.append(a*b)
                elif c == '/':
                    stack.append(int(float(b) / a))
            else:
                stack.append(c)
        return int(stack.pop())
        