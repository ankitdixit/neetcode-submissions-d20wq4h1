class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;
        for (const auto& s: strs) {
            string sortedS = s;
            sort(sortedS.begin(), sortedS.end());
            res[sortedS].push_back(s);
        }
        vector<vector<string>> retVec;
        retVec.reserve(res.size());
        for (const auto& pair : res) {
            retVec.push_back(pair.second);
        }
        return retVec;
    }
};
