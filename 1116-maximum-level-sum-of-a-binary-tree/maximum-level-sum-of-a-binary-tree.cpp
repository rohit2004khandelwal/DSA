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
    int maxLevelSum(TreeNode* root) {
        if(root == NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        int maxSum = INT_MIN;
        int ansLevel = 1;
        
        while(!q.empty()){
            int size = q.size();
            int currentSum = 0;
            for(int i=0; i<size; i++){
                TreeNode* front = q.front();
                q.pop();
                currentSum += front->val;
                if(front->left != NULL) q.push(front->left);
                if(front->right != NULL) q.push(front->right);
            }
            if(currentSum > maxSum){
                maxSum = currentSum;
                ansLevel = level;
            }
            level++;
        }
        return ansLevel;
    }
};