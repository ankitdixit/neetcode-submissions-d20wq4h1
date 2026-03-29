class Solution {
public:
    map<int, int> cache;
    int rob(vector<int>& nums) {
        return dp(nums, 0);
    }

    int dp(vector<int>& nums, int start) {
        if (start >= nums.size()) {
            return 0;
        }
        if (cache.find(start) != cache.end()) {
            return cache[start];
        }

        int sum= max(nums[start] + dp(nums, start+2), dp(nums, start+1));
        cache[start] = sum;
        return sum;
    }
};
