class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> result;
        unordered_set<int> seen;
        for(int num : nums){
            if(seen.count(num)){
                result.push_back(num);
            }else{
                seen.insert(num);
            }
        }
        return result;
    }
};