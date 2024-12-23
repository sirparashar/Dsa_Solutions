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
    int count = 0;

    void getswap(vector<int> res) {
        vector<int> t = res;
        sort(res.begin(), res.end());
        map<int, int> m;
        for (int i = 0; i < t.size(); i++) {
            m[t[i]] = i;
            // cout<<t[i]<<i;
        }
        for (int i = 0; i < res.size(); i++) {
            if (t[i] != res[i]) {
                int ci = m[res[i]];
                m[t[i]]=ci;
                m[t[ci]]=i;
                count++;
                swap(t[i],t[ci]);

            }
        }
    }
    int minimumOperations(TreeNode* root) {

        queue<TreeNode*> q;

        q.push(root);

        while (!q.empty()) {
            vector<int> level;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                auto node = q.front();
                q.pop();
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
                level.push_back(node->val);
            }
            getswap(level);
        }
        return count;
    }
};