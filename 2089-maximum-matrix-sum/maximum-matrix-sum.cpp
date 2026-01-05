class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int negCount = 0;
        long long sum = 0;
        long long minVal = INT_MAX;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] < 0){
                    negCount++;
                }
                long long val = llabs((long long)matrix[i][j]);
                sum += val;
                minVal = min(minVal, val);
            }
        }
        if(negCount % 2 == 0){
            return sum;
        }
        return (sum - (2 * minVal));
    }
};