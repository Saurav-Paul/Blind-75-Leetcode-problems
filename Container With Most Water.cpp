//https://leetcode.com/problems/container-with-most-water/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size() ;
        
        int low = 0, high = n - 1, mx = INT_MIN ;
        
        while(low < high){
            int curr = (high-low) * min(height[low],height[high]) ;
            
            mx = max(mx, curr) ;
            
            if(height[low] < height[high]) ++low;
            else --high;
        }
        
        return mx;
        
    }
};
