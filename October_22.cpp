# Maximum Frequency of an Element After Performing Operations II

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());
        long long left = 0, total = 0, ans = 1;

        for (long long right = 0; right < nums.size(); ++right) {
            total += nums[right];

            // Check if making all elements in the window equal to nums[right]
            // exceeds the total allowed increment (numOperations * k)
            while ((long long)nums[right] * (right - left + 1) - total > (long long)numOperations * k) {
                total -= nums[left];
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Example test case
    vector<int> nums = {1, 4, 5};
    int k = 1;
    int numOperations = 2;

    cout << sol.maxFrequency(nums, k, numOperations) << endl;
    // Expected Output: 2

    return 0;
}

