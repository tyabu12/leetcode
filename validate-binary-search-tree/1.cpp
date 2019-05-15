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
    bool aux(TreeNode* root, long minVal, long maxVal) {
        if (root == NULL) return true;
        if (root->val <= minVal) return false;
        if (root->val >= maxVal) return false;
        if (!aux(root->right, max(minVal, (long)root->val), maxVal)) return false;
        if (!aux(root->left, minVal, min(maxVal, (long)root->val))) return false;
        return true;
    }

public:
    bool isValidBST(TreeNode* root) {
        return aux(root, LONG_MIN, LONG_MAX);
    }
};
