class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>m;
        for(int i = 0; i < nums.size(); i++){
            int current = nums[i];
            int required = target - current;
            if(m.find(required) != m.end()){
             // if found
                return {i,m[required]};
            }
            m[current] = i;
        }
    return {-1,-1};
    }
};
