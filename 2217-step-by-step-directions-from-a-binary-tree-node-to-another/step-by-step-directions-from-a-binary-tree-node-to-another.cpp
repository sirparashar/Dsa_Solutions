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

    bool find(TreeNode* n, int val, string& p){
        if(n->val==val){
            return true;
        }
        if(n->left && find(n->left,val,p)){
            p.push_back('L');
        }
        else if(n->right&& find(n->right,val,p)){
            p.push_back('R');
        }
        return !p.empty();
    }
    string getDirections(TreeNode* root, int sval, int dval) {
        string s, d;
        find(root,sval,s);
        find(root,dval,d);

        while(!s.empty() && !d.empty() && s.back() == d.back()){
            s.pop_back();
            d.pop_back();
        }

        return string(s.size(),'U')+string(rbegin(d),rend(d));
    }
};