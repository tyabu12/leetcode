// dp with loop
// time: O(m*n), memory: O(n)
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[2][102] = {};
        for (int i = 0; i < n; i++) {
            dp[0][i] = dp[1][i] = 1;
        }
        int curIdx = 0, preIdx = 1;
        for (int i = 1; i < m; i++) {
          for (int j = 1; j < n; j++) {
            dp[curIdx][j] = dp[preIdx][j] + dp[curIdx][j - 1];
          }
          swap(curIdx, preIdx);
        }
        return dp[preIdx][n - 1];
    }
};
