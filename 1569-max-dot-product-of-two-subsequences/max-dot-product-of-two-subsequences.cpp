class Solution {
public:
    int solveRec(vector<int>& nums1, vector<int>& nums2, int i, int j){
        if(i >= nums1.size() || j >= nums2.size()) return -1e9;//WHY BCOZ HERE NEG NO ARE ALLOWED SO IT MIGHT HAPPEN THAT MAX PROD IS NEG NOW IN THIS CASE IT WILL ALWAYS RETURN 0
        int ans = INT_MIN;
        int val = nums1[i]*nums2[j];
        int take_both = (nums1[i]*nums2[j]) + solveRec(nums1, nums2, i+1, j+1);
        int take_i = solveRec(nums1, nums2, i, j+1);
        int take_j = solveRec(nums1, nums2, i+1, j);
        ans = max(val, max(take_both, max(take_i, take_j)));
        return ans;
    }
    //MEMO
    int solveMem(vector<int>& nums1, vector<int>& nums2, int i, int j, vector<vector<int>> &dp){
        if(i >= nums1.size() || j >= nums2.size()) return -1e9;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = INT_MIN;
        int val = nums1[i]*nums2[j];
        int take_both = (nums1[i]*nums2[j]) + solveMem(nums1, nums2, i+1, j+1, dp);
        int take_i = solveMem(nums1, nums2, i, j+1, dp);
        int take_j = solveMem(nums1, nums2, i+1, j, dp);
        ans = max(val, max(take_both, max(take_i, take_j)));
        dp[i][j] = ans;
        return dp[i][j];
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        // return solveRec(nums1, nums2, 0, 0);
        vector<vector<int>> dp(nums1.size()+1, vector<int>(nums2.size()+1, -1));
        return solveMem(nums1, nums2, 0, 0, dp);
    }
};