class Solution {
private:
    int myCompareNumberString(string s1, string s2) {
        if (s1.size() < s2.size()) return -1;
        if (s1.size() > s2.size()) return 1;
        for (int i=0;i<s1.size();i++) {
            if (s1[i] == s2[i]) continue;
            return (s1[i] > s2[i] ? 1 : -1);
        }
        return 0;
    }

public:
    int myAtoi(string str) {
        int idx = 0;
        // skip whitespace
        while (idx < str.size() && str[idx] == ' ') idx++;
        if (idx >= str.size()) return 0;
        // check sign
        bool minus;
        if (str[idx] == '+' || isdigit(str[idx])) {
            minus = false;
        } else if (str[idx] == '-') {
            minus = true;
        } else if (!isdigit(str[idx])) {
            return 0;
        }
        // skip sign
        if (!isdigit(str[idx])) idx++;
        // skip zeros
        while (idx < str.size() && str[idx] == '0') idx++;
        // parse number
        int startIdx = idx;
        while (idx < str.size() && isdigit(str[idx])) idx++;
        int endIdx = idx;
        string number = str.substr(startIdx, endIdx-startIdx);
        if (!minus) {
            return (myCompareNumberString(number, "2147483647") < 0 ? atoi(number.c_str()) : 2147483647);
        } else {
            return (myCompareNumberString(number, "2147483648") < 0 ? -atoi(number.c_str()) : -2147483648);
        }
    }
};
