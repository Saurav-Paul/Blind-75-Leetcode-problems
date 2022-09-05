//https://leetcode.com/problems/house-robber/

// iterative
class Solution {
public:

    int rob(vector<int>& nums) {
        vector< vector<int> > dp(nums.size()+1 , vector<int> (2,0)) ;
        
        dp[1][1] = nums[0] ;
        
        for(int i = 1; i < nums.size() ; i++){
            dp[i+1][0] = max(dp[i][1], dp[i][0]) ;
            dp[i+1][1] = max(dp[i][0], dp[i-1][1]) + nums[i] ;
        }
        
        return max(dp[nums.size()][0], dp[nums.size()][1]) ;

    }
};


// recursive
class Solution {
public:
    vector<int> dp;
    int find_answer(vector<int>&nums,int i){
        if(i >= nums.size()) return 0 ;
        
        if(dp[i] != -1) return dp[i] ;
        
        int curr_taken = nums[i] + find_answer(nums,i+2) ;
        int not_taken = find_answer(nums,i+1) ;
        
        return dp[i] = max(curr_taken, not_taken) ;
    }
    int rob(vector<int>& nums) {
        dp.assign(nums.size(), -1) ;
        return find_answer(nums,0) ;
    }
};
