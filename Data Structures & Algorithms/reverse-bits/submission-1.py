class Solution:
    def reverseBits(self, n: int) -> int:
        rev = n
        rev = (( rev << 16) & 0xFFFFFFFF) |  (rev >> 16)
        rev = ((rev & 0x00FF00FF) << 8) | ((rev & 0xFF00FF00) >> 8)
        rev = ((rev & 0x0F0F0F0F) << 4) | ((rev & 0xF0F0F0F0) >> 4)
        rev = ((rev & 0x33333333) << 2) | ((rev & 0xCCCCCCCC) >> 2)
        rev = ((rev & 0x55555555) << 1) | ((rev & 0xAAAAAAAA) >> 1)
        return rev
        