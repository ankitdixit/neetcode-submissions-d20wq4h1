class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int> pos_map;
        int n = s.size();
        int l = 0, max_len = 0;
        for(int r = 0; r < n; r++) {
            if (pos_map.find(s[r]) != pos_map.end()) {
                l = max(pos_map[s[r]] + 1, l);
            }
            pos_map[s[r]] = r;
            max_len = max(max_len, r - l + 1);
        }        
        return max_len;    
    }
};
