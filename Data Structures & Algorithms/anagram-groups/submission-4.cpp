class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> anagrams;
        unordered_map<string, vector<string>> count_map;
        for (string s : strs) {
            vector<int> count(26, 0);
            for (char c : s) {
                count[c - 'a']++;
            }
            string key ;
            for (int i = 0; i < 26; i++) {
                key += '#' + count[i];
            }
            count_map[key].push_back(s);
        }

        for (const auto& pair: count_map) {
            anagrams.push_back(pair.second);
        }
        return anagrams;
    }
};
