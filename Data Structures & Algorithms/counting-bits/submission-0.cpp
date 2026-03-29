class Solution {
public:
    vector<int> countBits(uint32_t n) {
        vector<int> dp (n+1);
        int offset = 1;
        for (int i = 1; i <= n; i++) {
            if (i == 2 * offset) {
                offset = i;
            }
            dp[i] = 1 + dp[i-offset];
        }
        return dp;
    }
};
