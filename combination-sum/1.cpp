class Solution {
private:
    vector<vector<int>> aux(vector<int>& candidates, int candidateIdx, int target) {
        vector<vector<int>> ans;
        if (candidateIdx >= candidates.size()) return ans;
        const int candidate = candidates[candidateIdx];
        vector<int> dd;
        for (int d = target; d >= 0; d -= candidate) {
            if (d == 0) {
                ans.push_back(dd);
            } else {
                auto subAns = aux(candidates, candidateIdx + 1, d);
                for (int j = 0; j < subAns.size(); j++) {
                    subAns[j].insert(subAns[j].end(), dd.begin(), dd.end());
                }
                ans.insert(ans.end(), subAns.begin(), subAns.end());
                dd.push_back(candidate);
            }
        }
        return ans;
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        return aux(candidates, 0, target);
    }
};
