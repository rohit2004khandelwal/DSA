class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i=0, j=n-1;
        int sum = 0;
        int ans = INT_MIN;
        while(i < j){
            sum = nums[i++] + nums[j--];
            ans = max(ans, sum);
        }
        return ans;
    }
};