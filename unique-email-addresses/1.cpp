class Solution {
private:
    pair<string, string> split(const string& src, char delim = ',') {
        auto n = src.find_first_of(delim);
        if (n == string::npos) {
            return make_pair(src, string(""));
        } else {
            return make_pair(src.substr(0, n), src.substr(n, string::npos));
        }
    }
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> st;
        for (int i = 0; i < emails.size(); i++) {
            auto names = split(emails[i], '@');
            string localName = names.first;
            localName.erase(remove(localName.begin(), localName.end(), '.'), localName.end());
            localName = split(localName, '+').first;
            const string domainName = names.second;
            st.insert(localName + domainName);
        }
        return st.size();
    }
};
