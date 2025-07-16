class Solution {
public:
    int solveMem(vector<int>& nums, int i, vector<int>& dp){
        //BASE CASE
        if(i >= nums.size()) return 0;
        //INCLUDE
        if(dp[i] != -1) return dp[i];
        int includeAns = nums[i] + solveMem(nums, i+2, dp); 
        //EXCLUDE
        int excludeAns = 0 + solveMem(nums, i+1, dp);
        dp[i] = max(includeAns, excludeAns);
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        vector<int> dp(n+1, -1);
        return solveMem(nums, i, dp);
    }
};