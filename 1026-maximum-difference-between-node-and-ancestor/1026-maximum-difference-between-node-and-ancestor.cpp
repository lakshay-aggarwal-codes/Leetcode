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
    int solve(TreeNode* root, int minVal, int maxVal) {
        if (root == NULL) {
            return 0;
        }

        minVal = min(minVal, root->val);
        maxVal = max(maxVal, root->val);
        ans = max(ans,maxVal - minVal);
         solve(root->left, minVal, maxVal);
         solve(root->right, minVal, maxVal);
        return root->val;
    }
    int maxAncestorDiff(TreeNode* root) {
        solve(root, root->val, root->val);
        return ans;
    }
};