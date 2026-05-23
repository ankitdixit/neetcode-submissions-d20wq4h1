class Solution {
private:
    struct Compare
    {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        }
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int, int> map;
       for (auto num : nums) {
            map[num]++;
       }

    
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        for (auto [key, value]: map) {
            pq.push({key, value});
            if (pq.size() > k) {
                pq.pop();
            }    
        }
        vector<int> result;
        while(!pq.empty()) {
            result.push_back(pq.top().first);
            pq.pop();
        }
        return result;
    }
};
