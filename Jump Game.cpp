//https://leetcode.com/problems/jump-game/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size() ;
        int mxReach = 0 ;
        
        for(int i = 0 ; i < n ; i++){
            if(mxReach < i) break ;
            if(mxReach + 1 >= n) break ;
            mxReach = max(mxReach, i + nums[i]) ;
        }
        
        return (mxReach + 1 < n ? false : true) ;
        
    }
};
