class Solution {
public:  
    int sumDivisors(int num){
        int divisors = 0;
        int sum = 0;
        for(int fact=1; fact*fact<=num; fact++){
            if(num%fact == 0){
                int other = num/fact;
                if(other == fact){
                    //PERFECT SQUARE NUM
                    divisors += 1;
                    sum += fact;
                }else{
                    divisors += 2;
                    sum += (fact + other);
                }
            }
            if(divisors > 4) return 0;//INVALID
        }
        return divisors == 4 ? sum : 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int result = 0;
        for(auto &num:nums){
            result += sumDivisors(num);
        }
        return result;
    }
};