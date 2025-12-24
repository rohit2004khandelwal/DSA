class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int count = 0;
        int sum = 0;
        for(auto i : apple) sum+=i;
        sort(capacity.begin(), capacity.end());
        int i = capacity.size()-1;
        while(i >= 0){
            sum = sum - capacity[i];
            count++;
            if(sum <= 0) break;
            i--;
        }
        return count;
    }
};