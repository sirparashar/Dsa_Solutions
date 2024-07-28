/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    void solve1(TreeNode* root,string& ans){
        if(root==NULL){
            ans+="#,";
            return;
        }
        ans+=to_string(root->val)+",";
        solve1(root->left,ans);
        solve1(root->right,ans);
    }
    string serialize(TreeNode* root) {
        string ans="";
        solve1(root,ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    int find(vector<int>& inorder,int element,int start,int end){
        for(int i=start;i<=end;i++){
            if(inorder[i]==element){
                return i;
            }
        }
        return -1;
    }
    TreeNode* solve(vector<int>& preorder,vector<int>& inorder,int& preIndex,int start,int end,int n){
        if(preIndex>=n || start>end){
            return NULL;
        }
        int element=preorder[preIndex++];
        int pos=find(inorder,element,start,end);
        TreeNode* root=new TreeNode(element);
        root->left=solve(preorder,inorder,preIndex,start,pos-1,n);
        root->right=solve(preorder,inorder,preIndex,pos+1,end,n);
        return root;
    }
    TreeNode* deserialize(string data) {
        vector<int> temp1,temp2;
        stringstream ss(data);
        string item;
        while (getline(ss, item, ',')) {
            if (item != "#") {
                temp1.push_back(stoi(item));
            }
        }
        temp2=temp1; //temp1 is preorder 
        sort(temp2.begin(),temp2.end()); //inorder
        //now we have both inorder and preorder we can make binary search tree now
        int preIndex=0;
        int n=temp2.size();
        return solve(temp1,temp2,preIndex,0,n-1,n);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;