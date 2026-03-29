/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int result;
        int k_copy = k;
        dfs(root, k_copy, result);
        return result;
    }

    void dfs (TreeNode* root, int& k, int& result) {
        if (root->left) dfs(root->left, k, result);
        if (k == 0) return;
        k--;
        if (k == 0) {
            result = root->val;
            return;
        }
        if (root->right) dfs(root->right, k, result);
        return;
    }



};
