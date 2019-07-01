class Solution {
public:
    int kthGrammar(int N, int K) {
        if (N == 1 || K == 1) return 0;
        const int t = kthGrammar(N - 1, (K + 1) / 2);
        if (t == 0) {
           return (K%2 == 0 ? 1 : 0);
        } else {
           return (K%2 == 0 ? 0 : 1);
        }
    }
};
