class Solution {
public:
    vector<int> getRow(int rowIndex) {

        vector<int> prev(rowIndex + 1, 0);
        vector<int> curr(rowIndex + 1, 0);

        prev[0] = 1;

        for (int i = 1; i <= rowIndex; i++) {
            curr[0] = 1;  // first element is always 1
            for (int j = 1; j < i; j++) {
                curr[j] = prev[j - 1] + prev[j];
            }
            curr[i] = 1;  // last element is always 1

            prev = curr; // copy current row to previous
        }

        return prev;
    }
};
