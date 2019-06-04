// time: O(length of words * number of words)
class Solution {
private:
    bool canTransform(const string& a, const string& b) {
        bool diff = false;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                if (diff) return false;
                diff = true;
            }
        }
        return diff;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Find end word index
        auto endWordItr = find(wordList.begin(), wordList.end(), endWord);
        if (endWordItr == wordList.end()) return 0;
        const int endWordIdx = distance(wordList.begin(), endWordItr);
        // Initialize queue
        vector<int> shortestSeq(wordList.size(), INT_MAX);
        queue<int> q;
        for (int i = 0; i < wordList.size(); i++) {
            if (canTransform(wordList[i], beginWord)) {
                shortestSeq[i] = 2;
                if (i == endWordIdx) return shortestSeq[i];
                q.push(i);
            }
        }
        // Breadth first search
        while (!q.empty()) {
            const int curIdx = q.front();
            q.pop();
            for (int i = 0; i < wordList.size(); i++) {
                if (shortestSeq[i] > shortestSeq[curIdx] + 1
                    && canTransform(wordList[i], wordList[curIdx])) {
                    shortestSeq[i] = shortestSeq[curIdx] + 1;
                    if (i == endWordIdx) return shortestSeq[i];
                    q.push(i);
                }
            }
        }
        return 0;
    }
};
