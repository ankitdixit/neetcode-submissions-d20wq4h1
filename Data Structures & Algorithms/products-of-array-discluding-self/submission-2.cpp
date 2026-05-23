class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> preMuls(nums.size());
        vector<int> postMuls(nums.size());
        int n = nums.size();
        //handle 0?
        int mul = 1;
        for (int i = 0; i < n; i++) {
            preMuls[i] = mul;
            if ( i < n-1) {
                mul = mul * nums[i];
            }
        }

        mul = 1;
        for (int i = n-1; i >= 0; i--) {
            postMuls[i] = mul;
            if ( i > 0) {
                mul = mul * nums[i];
            }
        }

        vector<int> result(nums.size(), 1);
        for (int i = 0; i < n; i++) {
            result[i] = preMuls[i] * postMuls[i];
        }   
        return result;
    }
};
