class Solution {
public:

    string encode(vector<string>& strs) {
        if (strs.empty()) return "";
        vector<int> sizes;
        string encoded = "";
        for (int i = 0; i < strs.size(); i++) {
            encoded += to_string(strs[i].size()) + ",";
        }
        encoded += "#";
        for (const auto& str : strs) {
            encoded += str;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        if (s.empty()) return {};
        vector<int> sizes;
        int i = 0;
        while(s[i] != '#') {
            string cur = "";
            while(s[i] != ',') {
                cur += s[i];
                i++;
            }
            sizes.push_back(stoi(cur));
            i++;
        }
        i++;
        vector<string> res;
        for(const auto& size : sizes) {
            res.push_back(s.substr(i, size));
            i += size;
        }
        return res;
    }
};
