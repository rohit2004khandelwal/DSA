class Solution {
public:
    int binarySearch(vector<int>& nums, int s, int e, int target){
        int k = -1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(nums[mid] < target){
                k = mid;
                s = mid+1;
            }else{
                e = mid-1;
            }
        }
        return k;
    }
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return 0;//IN CONSTRAINT GIVEN LENGHT CAN BE 1 SO REMEMBER IT
        sort(begin(nums), end(nums));
        int count = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == 0) continue;
            for(int j=i+1; j<n; j++){
                int sum = nums[i] + nums[j];
                int k = binarySearch(nums, j+1, n-1, sum);
                if(k != -1){
                    count += (k-j);
                }
            }
        }
        return count;
    }
};