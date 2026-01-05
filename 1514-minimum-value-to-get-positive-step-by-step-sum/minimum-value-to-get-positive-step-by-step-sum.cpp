class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int prefix=0;
        int minPfx = INT_MAX;
        for(int x : nums){
            prefix += x;
            minPfx = min(minPfx, prefix); 
        }
        return (minPfx<1) ? 1-minPfx : 1;
    }
};