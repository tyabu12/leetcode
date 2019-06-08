class Solution {
private:
    void fillLand(vector<vector<char>>& grid, int y, int x) {
        if (y < 0 || y >= grid.size()) return;
        if (x < 0 || x >= grid[y].size()) return;
        if (grid[y][x] == '0') return;
        grid[y][x] = '0';
        const int d[4][2] = {{-1, 0}, {0, -1}, {0, +1}, {+1, 0}};
        for (int i = 0; i < 4; i++)
            fillLand(grid, y + d[i][0], x + d[i][1]);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int num = 0;
        for (int y = 0; y < grid.size(); y++) {
            for (int x = 0; x < grid[y].size(); x++) {
                if (grid[y][x] == '0') continue;
                fillLand(grid, y, x);
                num++;
            }
        }
        return num;
    }
};
