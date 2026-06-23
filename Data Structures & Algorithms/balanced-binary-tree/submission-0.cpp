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

using namespace std;
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool balanced = true;
        dfs(root, balanced);
        return balanced;
    }
private:
    int dfs(TreeNode* node, bool& balanced) {
        if (node == nullptr) return 0;
        
        int left_height = dfs(node->left, balanced);
        int right_height = dfs(node->right, balanced);
        if (abs(right_height - left_height) > 1) {
            balanced = false;
        }
        return 1+ max(left_height, right_height);
    }
};
