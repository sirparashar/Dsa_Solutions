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
    void reverse(TreeNode* left1, TreeNode* right1, int l) {
        if (left1 == nullptr || right1 == nullptr) {
            return;
        }
        if (l % 2 != 0) {
            swap(left1->val, right1->val);
        }

        reverse(left1->left, right1->right, l + 1);
        reverse(right1->left, left1->right, l + 1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        reverse(root->left, root->right, 1);
        return root;
    }
};