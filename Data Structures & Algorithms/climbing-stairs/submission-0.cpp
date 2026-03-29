class Solution {
public:
    int climbStairs(int n) {
        vector<int> count;
        count.resize(n + 1, -1);
        count[1] = 1;
        count[2] = 2;
        return dp(n, count);
    }

    int dp(int n, vector<int>& count) {
        if(count[n] != -1) {
            return count[n];
        }
        count[n] = dp(n-1, count) + dp(n-2, count);
        return count[n];
    }
};
