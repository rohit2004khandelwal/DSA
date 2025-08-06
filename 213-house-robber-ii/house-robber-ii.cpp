class Solution {
public:
    int solve(vector<int>& nums, int n, int i){
        //BASE CASE
        if(i >= n) return 0;
        //INCLUDE
        int includeAns = nums[i] + solve(nums, n, i+2); 
        //EXCLUDE
        int excludeAns = 0 + solve(nums, n, i+1);
        int finalAns = max(includeAns, excludeAns);
        return finalAns;
    }
    //TOP DOWN
    int solveMem(vector<int>& nums, int n, int i, vector<int> &dp){
        //BASE CASE
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        //INCLUDE
        int includeAns = nums[i] + solveMem(nums, n, i+2, dp); 
        //EXCLUDE
        int excludeAns = 0 + solveMem(nums, n, i+1, dp);
        dp[i] = max(includeAns, excludeAns);
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0]; // Handle single house case
        int index=0;
        //IMP :- we need two independent dp arrays to avoid cross-contamination of memoized values.
        vector<int> dp1(n+1, -1);
        vector<int> dp2(n+1, -1);
        int ans1 = solveMem(nums, n-1, index, dp1);
        int ans2 = solveMem(nums, n, index+1, dp2);
        int ans = max(ans1, ans2);
        return ans;
    }
};