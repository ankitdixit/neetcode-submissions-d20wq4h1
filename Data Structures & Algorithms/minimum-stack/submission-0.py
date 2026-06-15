class MinStack:

    def __init__(self):
        self.stack = []
        self.minVal :int = float ("infinity")
        

    def push(self, val: int) -> None:
        self.stack.append(val)
        self.minVal = min(self.minVal, val)        

    def pop(self) -> None:
        ret_val = self.stack.pop()
        if self.minVal == ret_val:
            minV = float("infinity")
            for i in self.stack:
                minV = min (minV, i)
            self.minVal = minV
        return ret_val

    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.minVal

        
