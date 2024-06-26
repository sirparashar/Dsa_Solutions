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
    void inorder(TreeNode* root, vector<int> &arr) {

        if (root == nullptr) {
            return ;
        }
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);

    }

    TreeNode* construct(vector<int> arr, int start, int end) {
        if (start > end) {
            return nullptr;
        }

        int mid = start + (end - start) / 2;
        TreeNode* head = new TreeNode(arr[mid]);
        head->left = construct(arr, start, mid - 1);
        head->right = construct(arr, mid + 1, end);
        return head;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        inorder(root, arr);
        cout << arr.size();
        TreeNode* head = construct(arr, 0, arr.size() - 1);
        return head;
    }
};