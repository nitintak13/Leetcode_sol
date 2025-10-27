/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    int fun(TreeNode* root) {
        if (root == NULL)
            return 0;
        int left = fun(root->left);
        int right = fun(root->right);
        int ex = left + right + root->val - 1;
        ans += abs(left) + abs(right);
        return ex;
    }
    int distributeCoins(TreeNode* root) {
        if (root == NULL)
            return 0;
        int val = fun(root);
        return ans;
    }
};