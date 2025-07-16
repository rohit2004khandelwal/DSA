class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int evenCnt = 0;
        int oddCnt = 0;
        for(auto num : nums){
            if(num % 2 == 0){
                evenCnt++;
            }else{
                oddCnt++;
            }
        }
        int parity=nums[0]%2;
        int alternating = 1;

        for(int i=1;i<n;i++){
            int currParity = nums[i]%2;
            if(currParity != parity){
                alternating++;
                parity = currParity;
            }
        }
        return max({evenCnt, oddCnt, alternating});
    }
};