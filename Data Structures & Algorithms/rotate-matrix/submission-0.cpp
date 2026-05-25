class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int layer = 0 ; layer < n/2; layer++) {
            for (int i = layer; i < n - layer -1; i++) {
                int temp = matrix[layer][i];
                matrix[layer][i] = matrix[n-i-1][layer];
                matrix[n-i-1][layer] = matrix[n-1-layer][n-i-1];
                matrix[n-layer-1][n-i-1] = matrix[i][n-layer-1];
                matrix[i][n-layer-1] = temp;
            }
        }
    }
};
