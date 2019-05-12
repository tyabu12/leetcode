// dp with loop
// time: O(m*n), memory: O(m*n)
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[102][102];
        for (int i = 0; i <= max(m, n); i++) {
            dp[0][i] = dp[0][1] = 1;
        }
        for (int i = 1; i < m; i++) {
          for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
          }
        }
        return dp[m - 1][n - 1];
    }
};
