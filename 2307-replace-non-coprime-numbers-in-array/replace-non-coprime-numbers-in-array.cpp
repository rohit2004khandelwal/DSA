class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> result;
        for(int num:nums){
            while(!result.empty()){   //JAB TAK EMPTY NHI HOTA CHALTA RAHEGA EXPECT FOR GCD = 1
                int prev = result.back();
                int curr = num;
                int GCD = gcd(prev, curr);
                if(GCD == 1) break;
                result.pop_back();
                int LCM = prev/GCD * curr;
                num = LCM;  //merged number
            }
            result.push_back(num);
        }
        return result;
    }
};