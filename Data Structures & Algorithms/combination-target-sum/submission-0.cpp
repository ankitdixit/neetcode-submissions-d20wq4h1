class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return explore(nums, vector<int>{}, target, 0);
    }

    vector<vector<int>> explore(const vector<int>& nums, const vector<int>& selected, int target, int least_idx) {
        vector<vector<int>> res; 
        if (target == 0) {
            return {selected};
        }
    
        for (int i = least_idx; i < nums.size() && nums[i] <= target; i++) {
            vector<int> cur_selected = selected;
            cur_selected.push_back(nums[i]);
            auto combinations = explore(nums, cur_selected, target - nums[i], i);
            res.insert(res.end(), combinations.begin(), combinations.end());
        }
        return res;

    }

};
