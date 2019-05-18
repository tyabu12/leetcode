/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// time: O(n)
class Solution {
private:
    void aux(vector<vector<int>>& res, TreeNode* root, int level) {
        if (root == NULL) return;
        if (res.size() <= level) res.push_back({});
        res[level].push_back(root->val);
        const int nextLevel = level + 1;
        aux(res, root->left, nextLevel);
        aux(res, root->right, nextLevel);
    }

public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        aux(res, root, 0);
        for (int i = 1; i < res.size(); i += 2)
            reverse(res[i].begin(), res[i].end());
        return res;
    }
};
