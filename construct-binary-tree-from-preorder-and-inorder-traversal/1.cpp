/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// time: O(n^2)
class Solution {
private:
    TreeNode* aux(
        vector<int>& preorder,
        vector<int>::iterator preorderBegin,
        vector<int>& inorder,
        vector<int>::iterator inorderBegin,
        vector<int>::iterator inorderEnd) {
        if (inorderBegin == inorderEnd) return NULL;
        TreeNode* root = new TreeNode(*preorderBegin);
        auto inorderRoot = find(inorderBegin, inorderEnd, root->val);
        root->left = aux(
            preorder,
            preorderBegin + 1,
            inorder,
            inorderBegin,
            inorderRoot
        );
        root->right = aux(
            preorder,
            preorderBegin + (distance(inorderBegin, inorderRoot) + 1),
            inorder,
            inorderRoot + 1,
            inorderEnd);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return aux(
            preorder,
            preorder.begin(),
            inorder,
            inorder.begin(),
            inorder.end()
        );
    }
};
