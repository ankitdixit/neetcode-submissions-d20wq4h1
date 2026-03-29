class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while ( l < r) { 
            if (nums[l] <= nums[r]) return nums[l];
            // nums[l] > nums[r]
            int mid = (l + r ) / 2;
            if (nums[l] > nums[mid]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return nums[l];
    }
};
