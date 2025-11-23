class Solution {
public:
    int solveMem(int i, int rem, vector<int>& nums, vector<vector<int>> &dp){
        int n = nums.size();
        if(i >= n){
            if(rem == 0) return 0;
            return INT_MIN;
        }
        if(dp[i][rem] != -1) return dp[i][rem];

        int newRem = (rem + nums[i]) % 3;
        int inc = nums[i] + solveMem(i+1, newRem, nums, dp);
        int exc = solveMem(i+1, rem, nums, dp);
        dp[i][rem] = max(inc, exc);
        return dp[i][rem];
    }
    int maxSumDivThree(vector<int>& nums) {
        // return solveRec(0, 0, nums);
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(3, -1));
        return solveMem(0, 0, nums, dp);
    }
};