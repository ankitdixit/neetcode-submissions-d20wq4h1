class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool res = false;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if( dfs(board, word, {}, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(const vector<vector<char>>& board, string word, set<pair<int, int>> visited, int i, int j) {
        if(visited.contains({i,j}) || i >= board.size() || j >= board[0].size() || board[i][j] != word[0]) {
            return false;
        }
        if (word.size() == 1) {
            if (board[i][j] == word[0]) {
                return true;
            } else {
                return false;
            }
        }
        bool result;
        visited.insert({i,j});
        result = result | dfs(board, word.substr(1, word.size()), visited, i+1, j);
        result = result | dfs(board, word.substr(1, word.size()), visited, i, j+1);
        result = result | dfs(board, word.substr(1, word.size()), visited, i-1, j);
        result = result | dfs(board, word.substr(1, word.size()), visited, i, j-1);
        visited.erase({i,j});
        return result;
    }
};
