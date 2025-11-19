class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(original == nums[i]){
                original = 2 * original;
                i =- 1;
            }
        }
        return original;
    }
};