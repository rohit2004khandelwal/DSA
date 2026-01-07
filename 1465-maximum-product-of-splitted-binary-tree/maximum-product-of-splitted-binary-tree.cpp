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
    int M = 1e9+7;
    vector<long long> subs;
    long long postOrderTraversal(TreeNode* root){
        if(root == NULL) return 0;
        //LRN
        long long left = postOrderTraversal(root -> left);
        long long right = postOrderTraversal(root -> right);
        long long subSum = left + right + root->val;
        subs.push_back(subSum);
        return subSum;
    }
    int maxProduct(TreeNode* root) {
        long long totalSum = postOrderTraversal(root);
        long long maxProd = 0;
        for(auto s:subs){
            long long product = s*(totalSum - s);
            maxProd = max(maxProd, product);
        }
        return maxProd % M;
    }
};