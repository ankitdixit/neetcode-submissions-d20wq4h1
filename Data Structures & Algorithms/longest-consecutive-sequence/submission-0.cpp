class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int len = 1;
        int max_len = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1]) { 
                continue;
            } else if (nums[i] == nums[i-1] + 1) {
                len++;
                max_len = max(len, max_len);
            } else {
                len = 1;
            }
        }
        return max_len;
    }
};
