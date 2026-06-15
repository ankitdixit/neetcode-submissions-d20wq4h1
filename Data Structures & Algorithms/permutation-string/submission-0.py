class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False
        s1count, s2count = [0] * 26, [0] * 26
        for i in range(len(s1)):
            
            s1count[ord(s1[i]) - ord('a')] += 1
            s2count[ord(s2[i]) - ord('a')] += 1
        
        matches = 0
        for i in range(26):
            matches += (1 if s1count[i] == s2count[i] else 0)

        l = 0

        for r in range(len(s1), len(s2)):
            if matches == 26:
                return True
        
            r_idx = ord(s2[r]) - ord('a')
            s2count[r_idx] += 1

            if s1count[r_idx] == s2count[r_idx]:
                matches += 1
            elif s2count[r_idx] -1 == s1count[r_idx]:
                matches -= 1
            
            
            l_idx = ord(s2[l]) - ord('a')
            s2count[l_idx] -= 1
            l += 1
            
            if s1count[l_idx] == s2count[l_idx]:
                matches += 1
            elif s2count[l_idx] + 1 == s1count[l_idx]:
                matches -= 1
        return matches == 26
            
