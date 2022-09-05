//https://leetcode.com/problems/house-robber-ii/
class Solution {
public:
    int getMax(vector<int> &nums, int st, int sp){
        vector< vector<int> > dp(nums.size()+1 , vector<int> (2,0)) ;
        
        dp[st + 1][1] = nums[st] ;
        
        for(int i = st + 1; i <= sp; i++){
            dp[i+1][0] = max(dp[i][1], dp[i][0]) ;
            dp[i+1][1] = max(dp[i][0], dp[i-1][1]) + nums[i] ;
        }
        
        return max(dp[sp+1][0], dp[sp+1][1]) ;
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0] ;
        if(nums.size() == 2) return max(nums[0], nums[1]);
        return max(getMax(nums,0,nums.size() - 2), getMax(nums,1,nums.size()-1)) ;
        
    }
};
