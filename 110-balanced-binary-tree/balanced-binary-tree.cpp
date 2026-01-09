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
    int getHeight(TreeNode* root){
        if(root == NULL) return 0;
        int lh = getHeight(root->left);
        int rh = getHeight(root->right);
        int ansHeight = max(lh,rh) + 1;
        return ansHeight;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        //current node par check laga rha hun
        int lh = getHeight(root -> left);
        int rh = getHeight(root -> right);
        int absdiff = abs(lh-rh);
        bool status = absdiff <=1;
        if(!status) return false;
        //recursion 
        int leftans = isBalanced(root -> left);
        int rightans = isBalanced(root -> right);
        if(status && leftans && rightans) return true;
        else return false;
    }
};