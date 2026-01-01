class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp.insert({0, 1});
        int result = 0;
        int prefixSum = 0;
        for(int i=0; i<n; i++){
            prefixSum += nums[i];
            if(mp.find(prefixSum-goal) != mp.end()){
                result += mp[prefixSum-goal];
            }
            mp[prefixSum]++;
        }
        return result;
    }
};