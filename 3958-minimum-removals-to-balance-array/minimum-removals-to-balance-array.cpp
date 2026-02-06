class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int minRemovals = n;

        for (int i = 0; i < n; ++i) {
            // Binary search for the farthest j such that nums[j] <= nums[i] * k
            int left = i, right = n - 1, pos = i;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if ((long long)nums[mid] <= (long long)nums[i] * k) {
                    pos = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            // Elements kept = pos - i + 1, so removals = total - kept
            int removals = n - (pos - i + 1);
            minRemovals = min(minRemovals, removals);
        }

        return minRemovals;
    }
};
