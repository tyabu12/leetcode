class Solution {
private:
    int fillAndCountArea(vector<vector<int>>& grid, int x, int y) {
        if (y < 0 || y >= grid.size() || x < 0 || x >= grid[y].size()) return 0;
        if (grid[y][x] == 0) return 0;
        grid[y][x] = 0;
        int area = 1;
        area  += fillAndCountArea(grid, x, y - 1);
        area  += fillAndCountArea(grid, x - 1, y);
        area  += fillAndCountArea(grid, x + 1, y);
        area  += fillAndCountArea(grid, x, y + 1);
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for (int y = 0; y < grid.size(); y++) {
            for (int x = 0; x < grid[y].size(); x++) {
                maxArea = max(maxArea, fillAndCountArea(grid, x, y));
            }
        }
        return maxArea;
    }
};
