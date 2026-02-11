class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int maxSum = nums[0];
        int minSum = nums[0];
        if(n == 1) return max(abs(maxSum), abs(minSum));
        int ans = nums[0];
        for(int i=1; i<n; i++){
            int c1 = maxSum + nums[i];
            int c2 = nums[i];
            int c3 = minSum + nums[i];
            maxSum = max(c1, c2);
            minSum = min(c2, c3); 
            ans = max(ans, max(abs(maxSum), abs(minSum)));
        }
        return ans;
    }
};