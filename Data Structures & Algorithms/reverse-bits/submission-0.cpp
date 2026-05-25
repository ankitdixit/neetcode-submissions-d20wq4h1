class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int rev = 0;
        for(int i = 0; i < 32; i++) {
            bool set = n & 1<<i;
            rev = rev | set << (31-i);
        }
        return rev;
    }
};
