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
    void aux(vector<vector<int>>& res, TreeNode* root, int level) {
        if (root == NULL) return;
        if (res.size() <= level) res.push_back({});
        res[level].push_back(root->val);
        aux(res, root->left, level + 1);
        aux(res, root->right, level + 1);
    }

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        aux(res, root, 0);
        return res;
    }
};
