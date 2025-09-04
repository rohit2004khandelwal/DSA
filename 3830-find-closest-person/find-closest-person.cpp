class Solution {
public:
    int findClosest(int x, int y, int z) {
        int a = abs(z-x);
        int b = abs(z-y);
        return a == b ? 0 : a < b ? 1 : 2;
    }
};