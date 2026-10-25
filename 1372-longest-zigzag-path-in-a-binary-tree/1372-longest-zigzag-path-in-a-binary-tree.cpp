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
    int solve(TreeNode* root, int dir) {
        if (root == nullptr) {
            return 0;
        }
        int a = solve(root->left, 0);
        int b = solve(root->right, 1);
        ans = max(max(a, b), ans);
        if (dir == 0) {
            return b + 1;
        } else
            return a + 1;
    }
    int longestZigZag(TreeNode* root) {
        solve(root, 0);
        solve(root, 1);
        return ans;
    }
};