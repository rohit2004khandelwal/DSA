class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i=0,j=0;
        int n = nums.size();
        double sum = 0;
        double result = INT_MIN;
        double ans = 0;
        while(j < n){
            sum += nums[j];
            if(j-i+1 < k){
                j++;
            }
            else if(j-i+1 == k){
                ans = sum/k;
                result = max(result, ans);
                sum -= nums[i];
                i++;
                j++;
            }
        }
        return result;
    }
};