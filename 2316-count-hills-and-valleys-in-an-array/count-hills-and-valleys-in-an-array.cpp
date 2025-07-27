class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 1;
        int count = 0;
        while(j <= n-2){
            if(nums[i] < nums[j] && nums[j] > nums[j+1]){
                count++;
                i=j;
            }else if(nums[i] > nums[j] && nums[j] < nums[j+1]){
                count++;
                i=j;
            }
            j++;
        }
        return count;
    }
};