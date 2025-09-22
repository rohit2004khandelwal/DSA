class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        int maxFreq = 0;
        unordered_map<int, int> freq;
        for(int num:nums){
            freq[num]++;
            maxFreq = max(maxFreq, freq[num]);
        }
        int sum=0;
        for(auto &x : freq){
            if(x.second == maxFreq){
                sum += x.second;
            }
        }
        return sum;
    }
};