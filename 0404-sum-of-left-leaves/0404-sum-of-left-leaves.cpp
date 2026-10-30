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
    void solve(TreeNode* root, bool left) {
        if (root == NULL) {
            return;
        }
        if (!root->left && !root->right) {
            if (left)
             {   ans += root->val;
            return;}
        }
        solve(root->left, true);
        solve(root->right, false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
         solve(root, false);
        return ans;
    }
};