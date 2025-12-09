class Solution {
public:
    int M = 1e9+7;
    int specialTriplets(vector<int>& nums) {
        unordered_map<int, int> mp_left;
        unordered_map<int, int> mp_right;

        int result = 0;
        for(auto &num : nums){
            mp_right[num]++;
        }
        for(auto &num : nums){
            mp_right[num]--;
            int left = mp_left[num*2];
            int right = mp_right[num*2];

            result = (result + (1LL * left * right)) % M;

            mp_left[num]++;
        }
        return result;
    }
};