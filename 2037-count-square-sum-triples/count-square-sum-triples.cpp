class Solution {
public:
    int countTriples(int n) {
        unordered_set<int> squares;
        for(int i = 1; i <= n; i++){
            squares.insert(i * i);
        }

        int count = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                int sum = i*i + j*j;
                if(squares.count(sum)) {
                    count++;
                }
            }
        }
        return count;
    }
};
