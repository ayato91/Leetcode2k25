class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int prevLen = 0;
        int start = 0;
        for (int i = 1; i <= nums.size(); i++) {
            if (i == nums.size() || nums[i] <= nums[i - 1]) {
                int len = i - start;
                if (prevLen >= k && len >= k || len >= 2 * k) {
                    return true;
                }
                prevLen = len;
                start = i;
            }
        }
        return false;
    }
};