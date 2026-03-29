class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    count++;
                    visit(i,j, grid);
                }
            }
        }
        return count;
    }
    void visit(int i, int j, vector<vector<char>>& grid ) {
        if (i >= grid.size() || i < 0 || j >= grid[0].size() || j < 0 || grid[i][j] == '0' ) {
            return;
        }
        grid[i][j] = '0';
        visit(i+1, j, grid);
        visit(i, j-1, grid);
        visit(i-1, j, grid);
        visit(i, j+1, grid);
        return;
    }
};
