class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> st;//vector bhi create kar skte hai n is small
        int sum = 0;
        int maxNeg = INT_MIN;
        for(auto &num:nums){
            if(num <= 0){
                maxNeg = max(maxNeg, num);//[-2,-4,=6] for like this case bcoz emoty nhi kar skte
            }else if(!st.count(num)){
                sum += num;
                st.insert(num);
            }
        }
        return sum == 0? maxNeg : sum;
    }
};