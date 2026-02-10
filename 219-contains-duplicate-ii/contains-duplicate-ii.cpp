class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0,j=0;
        unordered_set<int> st;
        while(j < n){
            if(st.find(nums[j]) != st.end() && j-i<=k){
                return true;
            }
            st.insert(nums[j]);
            
            if(j-i+1 > k){
                st.erase(nums[i]);
                i++;
            }
            j++;
        }
        return false;
    }
};