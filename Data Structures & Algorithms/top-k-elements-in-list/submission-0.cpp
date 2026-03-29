class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, long> count_map;
        for(auto& num : nums) {
            count_map[num]++;
        }
        vector<pair<int, int>> arr;
        for (const auto& pair: count_map) {
            arr.push_back({pair.second, pair.first});
        } 
        sort(arr.rbegin(), arr.rend());
        vector<int> topK;
        for (int i = 0; i < k; i++) {
            topK.push_back(arr[i].second);
        }
        return topK;
    }
};
