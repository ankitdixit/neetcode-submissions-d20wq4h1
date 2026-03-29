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
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (const auto& entry: count_map) {
            pq.push({entry.second, entry.first});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> res;
        for(int i = 0; i < k; i++) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
