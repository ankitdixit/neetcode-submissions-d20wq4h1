class Solution:

    def encode(self, strs: List[str]) -> str:
        encoded = ""
        for s in strs:
            if s == "":
                encoded += "0#"
            else:
                encoded += str(len(s)) + "#" + s if len(s) else ""
        # print(encoded)
        return encoded
    
    def decode(self, s: str) -> List[str]:
        result = []
        print(s)
        while len(s):
            str_len, rest = s.split("#", 1)
            length = int(str_len)
            # print(length)
            # print(rest)
            # print(f"string : {rest[:length]}")
            result.append(rest[:length])
            s = rest[length:]
            # print(s)
        return result

