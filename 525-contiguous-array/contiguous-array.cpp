class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = -1;
        int result = 0; //LENGTH
        int prefixSum = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == 0) nums[i] = -1;
            prefixSum += nums[i];
            if(mp.find(prefixSum) != mp.end()){
                int length = i - mp[prefixSum];
                result = max(result, length);
            }else{
                mp[prefixSum] = i;
            }
        }
        return result;
    }
};