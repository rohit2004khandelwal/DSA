class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return -1;
        vector<int> leftMin(n, 0);
        vector<int> rightMin(n, 0);
        
        leftMin[0] = nums[0];
        rightMin[n-1] = nums[n-1];
        int sum = 0;
        int ans = INT_MAX;
        for(int i=1; i<n; i++){
            leftMin[i] = min(leftMin[i-1], nums[i]);
        }
        for(int i=n-2; i>=0; i--){
            rightMin[i] = min(rightMin[i+1], nums[i]);
        }
        for(int j=1; j<n-1; j++){
            if(leftMin[j-1] < nums[j] && rightMin[j+1] < nums[j]){
                sum = leftMin[j-1] + nums[j] + rightMin[j+1];
                ans = min(ans, sum);
            }
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};