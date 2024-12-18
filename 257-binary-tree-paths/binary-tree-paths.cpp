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
      
    void getpaths(TreeNode* root, vector<string>&res, string str ){
        if(root==nullptr){
            return ;
        }
        if(root->left==nullptr && root->right==nullptr){
            str+=to_string(root->val);
            res.push_back(str);
            str="";
            return;
        }
          
         str+=to_string(root->val)+"->";
         getpaths(root->left,res,str);
         getpaths(root->right,res,str);


    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>res;
        getpaths(root,res,"");
        return res;
    }
};