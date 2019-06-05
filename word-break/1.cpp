class Solution {
private:
    bool contains(const string& s1, const string& s2) {
        if (s1.size() > s2.size()) return false;
        return equal(begin(s1), end(s1), begin(s2));
    }

    bool aux(
        const string& s,
        int sStart,
        vector<int>& memo,
        vector<string>& wordDict
    ) {
        if (memo[sStart] != -1) return (memo[sStart] != 0);
        const string ss = s.substr(sStart);
        for (int i = 0; i < wordDict.size(); i++) {
            const string& word = wordDict[i];
            if (!contains(word, ss)) continue;
            if (aux(s, sStart + word.size(), memo, wordDict)) {
                memo[sStart] = 1;
                return true;
            }
        }
        memo[sStart] = 0;
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> memo(s.size() + 1, -1);
        memo[s.size()] = 1;
        return aux(s, 0, memo, wordDict);
    }
};
