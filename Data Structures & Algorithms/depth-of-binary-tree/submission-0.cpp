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
    int test_depth(TreeNode* node, int depth) {
        if (node == nullptr) return depth;
        return max(test_depth(node->left, depth + 1), test_depth(node->right, depth + 1));
    }
    int maxDepth(TreeNode* root) {
        return test_depth(root, 0);
    }
};
