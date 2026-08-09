class Solution :
    def dfs(self, i :int, open :int, s :str, memo :dict[int, dict[int, int]]) -> bool:
        if i == len(s): 
            if open == 0:
                return True
            else:
                return False
        
        if i in memo and open in memo[i]:
            return memo[i][open]
        result = False
        
        if s[i] == '(':
            result = self.dfs(i+1, open+1, s, memo)
        elif s[i] == ')':
            if open <= 0:
                result = False
            else:
                result =  self.dfs(i+1, open - 1, s, memo)
        elif s[i] == '*':
            if open >= 0:
                result = result or self.dfs(i+1, open -1, s, memo)
            result = result or self.dfs(i+1, open, s, memo)
            result = result or self.dfs(i+1, open+1, s, memo)
        if i not in memo:
            memo[i] = {}
        memo[i][open] = result
        return result

    def checkValidString(self, s :str) -> bool:
        if s == '':
            return True
        memo :dict[int, dict[int, int]] = {}
        return self.dfs(0, 0, s, memo)

      
