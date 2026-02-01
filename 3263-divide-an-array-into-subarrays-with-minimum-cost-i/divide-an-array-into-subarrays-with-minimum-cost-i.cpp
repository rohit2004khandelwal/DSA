class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        // int minVal = INT_MAX;
        // int count = 1;
        // for(int i=1; i<n; i++){
        //     minVal = min(minVal, nums[i]);
        // }
        // sum += minVal;
        sort(nums.begin()+1, nums.end());
        sum += nums[1] + nums[2];
        return sum;
    }
};