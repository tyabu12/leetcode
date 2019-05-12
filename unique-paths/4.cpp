// dp with loop
// time: O(m*n), memory: O(n)
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[102];
        for (int i = 0; i < n; i++) dp[i] = 1;
        for (int i = 1; i < m; i++) {
          for (int j = 1; j < n; j++) {
            dp[j] += dp[j - 1];
          }
        }
        return dp[n - 1];
    }
};
