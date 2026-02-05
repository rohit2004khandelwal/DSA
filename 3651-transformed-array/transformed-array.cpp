class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        int idx;
        vector<int> result(n);
        for(int i=0; i<n; i++){
            if(nums[i] > 0){
                idx = (i + nums[i]) % n;
                result[i] = nums[idx];
            }else if(nums[i] < 0){
                idx = (i - abs(nums[i]) % n + n) % n;
                result[i] = nums[idx];
            }else{
                result[i] = nums[i];
            }
        }
        return result;
    }
};