/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Time: O(N)
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL)
            return false;
        else if (root->left == NULL && root->right == NULL) // leaf
            return (root->val == sum);
        else
            return (hasPathSum(root->left, sum - root->val)
                    || hasPathSum(root->right, sum - root->val));
    }
};
