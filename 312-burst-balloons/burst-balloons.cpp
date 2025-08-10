class Solution {
public:
    int solveRec(vector<int>& nums, int start, int end){
        if(start > end) return 0;
        int coins = INT_MIN;
        for(int i=start;i<=end;i++){
            coins = max(coins,
                        nums[start-1]*nums[i]*nums[end+1]
                        + solveRec(nums, start, i - 1) + solveRec(nums,i + 1, end)
                      );
        }
        return coins;
    }
    //TOP DOWN
    int solveMem(vector<int>& nums, int start, int end, vector<vector<int>> &dp){
        if(start > end) return 0;
        if(dp[start][end] != -1) return dp[start][end];
        int coins = INT_MIN;
        for(int i=start;i<=end;i++){
            coins = max(coins,
                        nums[start-1]*nums[i]*nums[end+1]
                        + solveMem(nums, start, i - 1, dp) + solveMem(nums,i + 1, end, dp)
                      );
        }
        return dp[start][end] = coins;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        // return solveRec(nums, 1, nums.size() - 2);
        vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1, -1));
        return solveMem(nums, 1, nums.size() - 2, dp);
    }
};