class Solution {
public:
    int helper(TreeNode* root, int sum) {
        if (root == nullptr) {
            return sum;
        }
        
        // Traverse the right subtree first
        sum = helper(root->right, sum);
        
        // Update the current node's value
        sum += root->val;
        root->val = sum;
        
        // Traverse the left subtree
        return helper(root->left, sum);
    }

    TreeNode* bstToGst(TreeNode* root) {
        helper(root, 0);
        return root;
    }
};
