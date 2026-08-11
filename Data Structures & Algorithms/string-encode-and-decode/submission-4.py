class Solution:

    def encode(self, strs: List[str]) -> str:
        encoded = ""
        for s in strs:
            encoded += str(len(s)) + "#" + s
        return encoded
    
    def decode(self, s: str) -> List[str]:
        result = []
        i = 0
        while i < len(s):
            j = s.index("#", i)
            str_len = int(s[i:j])
            result.append(s[j+1:j+1+str_len])
            i = j + str_len + 1
        return result

