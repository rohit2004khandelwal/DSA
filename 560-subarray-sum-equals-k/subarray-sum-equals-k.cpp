class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp.insert({0, 1});
        int prefixSum = 0;
        int result = 0;
        for(int i=0; i<n; i++){
            prefixSum += nums[i];
            if(mp.find(prefixSum-k) != mp.end()){
                result += mp[prefixSum-k];
            }
            mp[prefixSum]++;
        }
        return result;
    }
};