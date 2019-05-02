class Solution {
private:
    char getLeftBracket(char r) {
        switch (r) {
        case ')': return '(';
        case ']': return '[';
        case '}': return '{';
        default: assert(false);
        }
    }

public:
    bool isValid(string s) {
        stack<char> st;
        for (int i=0;i<s.size();i++) {
            const char ch = s[i];
            switch (ch) {
            // open brackets
            case '(':
            case '[':
            case '{':
              st.push(ch);
              break;
            // close brackets
            case ')':
            case ']':
            case '}':
               if (st.empty()) return false;
               if (st.top() != getLeftBracket(ch)) return false;
               st.pop();
               break;
            // others
            default: assert(false);
            }
        }
        return st.empty();
    }
};
