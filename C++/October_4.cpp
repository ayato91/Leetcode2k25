/*
Solution for October 4th, 2025
Container with most water

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0, j=height.size()-1; //Two pointers, one at the very beginning and one at the very end
        int area=0;
        while(i<j){ //Loop as long as the left pointer is to the left of the right pointer.
            area = max(min(height[i], height[j])*(j-i), area); //Area of the current container = min(height[i], height[j])*(j-i). Update the area if current area is larger
            if(height[j]>height[i]){
                i++; //The left line is shorter, so move the left pointer to the right.
            }else{
                j--; //The right line is shorter (or equal), so move the right pointer to the left.
            }
        }
        return area;
    }
};