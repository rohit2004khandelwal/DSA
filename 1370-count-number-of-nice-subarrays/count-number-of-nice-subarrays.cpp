class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = 1;
        int result = 0;
        int prefixSum = 0;
        for(int i=0; i<n; i++){
            if(nums[i] % 2 == 0) nums[i] = 0;
            else nums[i] = 1;
            prefixSum += nums[i];
            if(mp.find(prefixSum-k) != mp.end()){
                result += mp[prefixSum-k];
            }
            mp[prefixSum]++;
        }
        return result;
    }
};