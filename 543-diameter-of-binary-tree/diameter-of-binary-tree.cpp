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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
         height(root,diameter);
         return diameter-1;

    }

    int height(TreeNode* root,int& diameter){
     
        if(root==nullptr){
            return 0;
        }
        int leftheight = height(root->left, diameter);
        int rightheight = height(root->right,diameter);

        int dia = leftheight+rightheight+1;
        diameter = max(diameter,dia);

        return (max(leftheight,rightheight)+1);

    }
};