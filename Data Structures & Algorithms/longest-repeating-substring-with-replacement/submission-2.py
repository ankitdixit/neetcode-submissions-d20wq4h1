class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        l, maxf, max_len = 0, 0, 0
        count = {}
        for r in range(len(s)):
            count[s[r]] = 1 + count.get(s[r], 0)
            maxf = max(maxf, count[s[r]])
            while ( r - l + 1 - maxf > k):
                count[s[l]] -= 1
                l += 1;
            max_len = max(max_len, r - l + 1)
        return max_len
        