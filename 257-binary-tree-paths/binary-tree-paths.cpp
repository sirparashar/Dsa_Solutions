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
    vector<string> res;
    void getpaths(TreeNode* root, string str) {
        if (root == nullptr) {
            return;
        }
        if (root->left == nullptr && root->right == nullptr) {
            str += to_string(root->val);
            res.push_back(str);
            str = "";
            return;
        }

        str += to_string(root->val) + "->";
        getpaths(root->left, str);
        getpaths(root->right, str);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        getpaths(root, "");
        return res;
    }
};