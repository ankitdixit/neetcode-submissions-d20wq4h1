class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> cache1(n, -1);
        vector<int> cache2(n, -1);
        if (nums.size() == 1) {
            return nums[0];
        }
        
        return max (rob(nums, 1, n -1, cache1), nums[0] + rob(nums, 2, n-2, cache2));
    }

    int rob(vector<int>& nums, int l, int r, vector<int>& cache) {
        int n = nums.size();
        if (l > r) {
            return 0;
        }

        if(cache[l] != -1) {
            return cache[l];
        }

        cache[l] = max(
            (nums[l] + rob(nums, l+2, r, cache)),
            rob(nums,l+1,r, cache)); 
        return cache[l];
    }
};
