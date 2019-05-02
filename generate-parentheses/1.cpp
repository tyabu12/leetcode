class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) return {""};
        if (n == 1) return {"()"};
        vector<string> ans;
        for (int i=0;i<n;i++) {
            auto v1 = generateParenthesis(i);
            auto v2 = generateParenthesis(n-i-1);
            for (auto it1 = v1.begin(); it1 != v1.end(); it1++) {
                for (auto it2 = v2.begin(); it2 != v2.end(); it2++) {
                    ans.push_back('(' + *it1 + ')' + *it2);
                }
            }
        }
        return ans;
    }
};
