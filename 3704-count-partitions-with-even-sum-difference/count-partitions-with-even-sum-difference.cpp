class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(int i=0; i<n; i++){
            totalSum += nums[i];
        }
        int leftSum = 0;
        int rightSum = 0;
        int partitions = 0;
        for(int i=0; i<n-1; i++){
            leftSum += nums[i];
            rightSum = totalSum - leftSum;
            if((rightSum - leftSum) % 2 == 0){
                partitions++;
            }
        }
        return partitions;
    }
};