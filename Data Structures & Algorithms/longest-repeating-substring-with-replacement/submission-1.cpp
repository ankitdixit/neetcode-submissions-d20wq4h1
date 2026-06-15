#include <cassert>

class Solution {
   public:
    int characterReplacement(string s, int k) {
        int freq[26] = {};
        int l = 0, max_len = 0, max_freq = -1;
        for (int r = 0; r < s.size(); r++) {
            ++freq[s[r] - 'A'];
            max_freq = max (max_freq, freq[s[r] - 'A']);
            while (r - l + 1 - max_freq  > k) {
                --freq[s[l] - 'A'];
                ++l;   
            }
            max_len = max(max_len, r - l + 1);
        }

        return max_len;
    }
};
