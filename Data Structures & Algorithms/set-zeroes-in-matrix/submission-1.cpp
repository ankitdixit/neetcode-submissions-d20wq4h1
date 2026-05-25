class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<bool> zero_rows(m, 0);
        vector<bool> zero_columns(n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    zero_rows[i] = 1;
                    zero_columns[j] = 1;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (zero_rows[i] || zero_columns[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
