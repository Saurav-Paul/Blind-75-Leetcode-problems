//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size() ;
        
        int st = 0, sp = n - 1;
        int ans = INT_MAX;
        
        while(st <= sp){
            int mid = (st + sp) / 2 ;

            if(nums[mid] <= nums[sp]){
                sp = mid - 1;
                ans = min(ans, nums[mid]) ;
            }
            else{
                st = mid + 1;
            }
        }
        
        return ans ;
    }
};
