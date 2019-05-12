// dp with memo array
// time: O(m*n), memory: O(m*n)
class Solution {
private:
    int dp[102][102];

    int aux(int m, int n) {
        if (dp[m][n] != 0) return dp[m][n];
        dp[m][n] = dp[n][m] = aux(m - 1, n) + aux(m, n - 1);
        return dp[m][n];
    }

public:
    int uniquePaths(int m, int n) {
        for (int i = 0; i <= max(m, n); i++) {
            dp[1][i] = dp[i][1] = 1;
        }
        return aux(m, n);
    }
};
