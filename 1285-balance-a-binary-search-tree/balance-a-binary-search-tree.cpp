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
    void inorder(TreeNode* root, vector<int> &in){
        if(root == NULL) return;
        inorder(root->left, in);
        in.push_back(root->val);
        inorder(root->right, in);
    }
    TreeNode* buildTree(vector<int> &in, int s, int e){
         if(s>e) return NULL;
        int mid = (s+e)/2;
        // 1case
        int element = in[mid];
        TreeNode* root = new TreeNode(element);
        // rec

        root->left = buildTree(in, s, mid-1);
        root->right = buildTree(in,mid+1,e);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> in;
        inorder(root, in);
        int s=0;
        int e=in.size()-1;
        return buildTree(in, s, e);
    }
};