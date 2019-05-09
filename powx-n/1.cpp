class Solution {
public:
    double myPow(double x, int n) {
        // binary expansion
        double r = 1., xp = x;
        for (long a = abs((long)n); a >= 1; a /= 2) {
            if (a % 2 == 1) {
                r *= xp;
            }
            xp *= xp;
        }
        if (n < 0) r = 1. / r; // inverse
        return r;
    }
};
