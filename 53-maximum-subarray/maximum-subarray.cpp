class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int best = nums[0];
        int ans = nums[0];
        for(int i=1; i<n; i++){
            int c1 = best + nums[i];
            int c2 = nums[i];
            best = max(c1, c2);
            ans = max(ans, best);
        }
        return ans;
    }
};