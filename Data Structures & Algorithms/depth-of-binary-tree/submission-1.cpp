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
    int maxDepth(TreeNode* root) {
        stack<pair<TreeNode*, int>> s;
        s.push({ root, 0 });

        int max_depth = 0;

        while(!s.empty()) {
            auto p { s.top() };
            auto node = p.first;
            int depth = p.second;
            s.pop();
            if (node == nullptr) {
                max_depth = max(max_depth, depth);
                continue;
            }
            
            s.push({ node->left, depth + 1 });
            s.push({ node->right, depth + 1 });
        }

        return max_depth;
    }
};
