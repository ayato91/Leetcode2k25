/*
Problem: 3350. Adjacent Increasing Subarrays Detection II
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int maxl = 0; //Maximum Length
        int prevl = 0; //Previous Length
        int currl = 0; //Curretn Length
        int n = nums.size();
      
        for (int i=0; i<n; i++){
            currl++;
            if (i==n-1 || nums[i] >= nums[i+1]) {
                maxl = max({maxl, currl/2, min(prevl, currl)});
              
                prevl=currl;
                currl=0;
            }
        }
        return maxl;
    }
};