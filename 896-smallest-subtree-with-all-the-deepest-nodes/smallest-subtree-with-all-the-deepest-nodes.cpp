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
unordered_map<int, int> mp;
    int maxD = 0;
    TreeNode* LCA(TreeNode* root){
        if(root == NULL) return NULL;
        if(mp[root->val] == maxD) return root;

        TreeNode* leftAns = LCA(root->left);
        TreeNode* rightAns = LCA(root->right);

        if(leftAns == NULL && rightAns == NULL) return NULL;
        else if(leftAns == NULL && rightAns != NULL) return rightAns;
        else if(leftAns != NULL && rightAns == NULL) return leftAns;
        else{
            // both leftAns and rightAns are non null
            return root;
        }
    }
    void depth(TreeNode* root, int d){
        if(root == NULL) return;
        maxD = max(maxD, d);
        mp[root -> val] = d;
        depth(root->left, d+1);
        depth(root->right, d+1);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        depth(root, 0);  
        return LCA(root);
    }
};