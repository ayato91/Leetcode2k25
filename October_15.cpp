#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int maxAdjacentIncreasingSubarrays(std::vector<int>& nums) {
        int n = nums.size();
        
        if (n < 2) {
            return 0;
        }
        
        std::vector<int> dp_inc(n, 1);
        
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                dp_inc[i] = dp_inc[i - 1] + 1;
            } else {
                dp_inc[i] = 1;
            }
        }
        
        std::vector<int> dp_inc_start(n, 1);

        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                dp_inc_start[i] = dp_inc_start[i + 1] + 1;
            } else {
                dp_inc_start[i] = 1;
            }
        }
        
        int max_k = 0;
        
        for (int i = 1; i < n; ++i) {
            int k1 = dp_inc[i - 1]; 
            int k2 = dp_inc_start[i];
            
            int current_k = std::min(k1, k2);
            
            max_k = std::max(max_k, current_k);
        }
        
        return max_k;
    }
};