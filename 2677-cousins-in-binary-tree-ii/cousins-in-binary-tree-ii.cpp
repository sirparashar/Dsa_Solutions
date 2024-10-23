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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(!root){
            return nullptr;
        }

        queue<TreeNode*> q;
        int prev = root->val;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            int cur =0;
            while(n>0){
                TreeNode* temp = q.front();
                q.pop();

                int lrsum  = (temp->left?temp->left->val:0) + (temp->right?temp->right->val:0);

                if(temp->left){
                    temp->left->val = lrsum;
                    q.push(temp->left);
                }

                if(temp->right){
                    temp->right->val = lrsum;
                    q.push(temp->right);
                }

                cur+= lrsum;
                temp->val = prev-temp->val;
                n--;

            }

            prev=cur;
        }

        return root;
        
    }
};