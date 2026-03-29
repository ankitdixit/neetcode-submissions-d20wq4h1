class Solution {
public:
    int search(vector<int>& nums, int target) {
    int n = nums.size();
    if (n == 1) {
        nums[0] == target ? 0 : -1;
    }
    int pivot = findPivot(nums);
    int l = 0, r = n-1;
    if (target >= nums[l] && target <= nums[pivot-1]) {
        return find(nums, target, 0, pivot-1);
    } else {
        return find(nums, target, pivot, r);
    }
    return -1; // never reached
    } 

    int findPivot(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while (l < r) {
            int m = (l + r) / 2;
            if (nums[m] <= nums[r]) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }

    int find(vector<int>& nums, int target, int l, int r) {
        while(l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return -1;
    }
};
