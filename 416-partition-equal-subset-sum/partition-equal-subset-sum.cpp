class Solution {
public:
    bool solve(vector<int>& nums, int target , int i){
        if(target<0 || i>=nums.size()) return false;
        if(target == 0) return true;
        bool inc = solve(nums , target-nums[i],i+1);
        bool exc = solve(nums , target , i+1);
        return inc || exc;
    }
    //TOP DOWN APPROACH
    bool solveMem(vector<int>& nums, int target , int i, vector<vector<int>> &dp){
        if(target<0 || i>=nums.size()) return false;
        if(target == 0) return true;

        if(dp[target][i] != -1) return dp[target][i];
        bool inc = solveMem(nums , target-nums[i],i+1, dp);
        bool exc = solveMem(nums , target , i+1, dp);
        dp[target][i] = inc || exc;
        return dp[target][i];
    }
    //BOTTOM UP APPROACH
    bool solveTab(vector<int>& nums, int target){
        int n= nums.size();
        vector<vector<bool>> dp(target+1, vector<bool>(n+1, 0));
        //BASE CASE ANALYSIS
        for(int col =0;col<=nums.size();col++){
            dp[0][col] = true;
        }

        for(int t=1;t<=target;t++){
            for(int i=n-1;i>=0;i--){
                bool inc = false;
                if (t - nums[i] >= 0) {
                     inc = dp[t - nums[i]][i + 1];
                }
                bool exc = dp[t][i+1];
                dp[t][i] = inc || exc;
            }
        }
        return dp[target][0];
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(), 0);
        if(sum%2 != 0) return false;
        int target = sum>>1;
        // return solve(nums,target,0);
        // vector<vector<int> > dp(target+1, vector<int>(n+1, -1));
        // return solveMem(nums, target, 0, dp);
        return solveTab(nums,target);
    }
};