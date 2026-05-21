class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;
        for (string str: strs) {
            encoded += to_string(str.size()) + '#' + str;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;
        while(i < s.size()) {
            int ptr = i;
            while (s[ptr] != '#') {
                ptr++;
            }
            int length = stoi(s.substr(i, ptr - i));
            i = ptr+1;

            decoded.push_back(s.substr(i, length));
            i += length;
        }
        return decoded;
    }
};
